import processing.core.*; 
import processing.data.*; 
import processing.event.*; 
import processing.opengl.*; 

import processing.serial.*; 

import java.util.HashMap; 
import java.util.ArrayList; 
import java.io.File; 
import java.io.BufferedReader; 
import java.io.PrintWriter; 
import java.io.InputStream; 
import java.io.OutputStream; 
import java.io.IOException; 

public class IHCcontroller extends PApplet {



btn btnConect;
Module[] mdl = new Module[8];
Serial myPort;
String log = "";
boolean conected=false;

public void setup() {
  
  background(240);
  btnConect = new btn(10,10,80,30,"Conect");
  btnConect.display();
  int x=50,y=70;
  for(int i=0 ; i<8; i++){
    mdl[i] = new Module(x,y,i+1);
    mdl[i].display();
    y+=30;
  }
  
}

public void draw() {
   btnConect.mouseover();
   printlog();
   for(int i=0 ; i<8; i++){
    mdl[i].mouseover();
   }
}

public void printlog(){
  textAlign(LEFT);
  fill(240);
  stroke(200);
  rect(400,50,200,270);
  fill(0);
  text(log,420,75);
  if(log.length()>130){
    log=log.substring(log.indexOf("\n")+1);
  }
}

public void mousePressed() {
  if(btnConect.mouseover()){
    if(btnConect.click()){
      String portName = Serial.list()[0];
      log+="Conected to "+portName+"\n";
      myPort = new Serial(this, portName, 9600);
    }else{
      myPort.stop();
      conected=false;
      for(int i =0;i<8;i++){
        mdl[i].reset();
      }
      log+="Disconected"+"\n";
    }
  }
  if(conected){
    for(int i =0;i<8;i++){
      int index = mdl[i].mouseover();
      if(index!=-1){
        mdl[i].click(index);
        myPort.write(i);
        myPort.write(mdl[i].getData());
        log+="Send : "+hex(i,2)+hex(mdl[i].getData(),2)+"\n";
      }
    }
  }
}

public void serialEvent(Serial p) { 
  log += p.readString();
  conected=true;
}
class btn{
int x,y,w,h;
int txtx,txty;
String txt;
int red = 255,green = 0,blue=0;
  btn(int btnConectx,int btnConecty,int btnConectsizeW,int btnConectsizeH,String txt){
      this.x=btnConectx;
      this.y=btnConecty;
      this.w=btnConectsizeW;
      this.h=btnConectsizeH;
      this.txt=txt;
      txtx= btnConectx+btnConectsizeW/2;
      txty=btnConecty+5+btnConectsizeH/2;
  }
  
  public void display(){
    fill(red,green,blue);
    rect(x,y,w,h);
    textAlign(CENTER);
    fill(0);
    text(txt,txtx,txty);
  }
  
  public boolean mouseover(){
   if (mouseX >= x && mouseX <= x+w && 
      mouseY >= y && mouseY <= y+h) {
        red= 250;
        display();
        return true;
    } else {
        red= 190;
        display();
        return false;
    }
  }
  
  public boolean click(){
    if(green==0){
      green = 255;
      txt ="Conected";
      display();
      return true;
    }else{
      green = 0;
      txt="Conect";
      display();
      return false;
    }
    
  }
  
}
class Module{
  int x,y,id;
  int[] checked={255,255,255,255,255,255,255,255 };
  int clickx = 0;
  Module(int x,int y,int id){
    this.x=x;
    this.y=y;
    this.id=id;
    
  }
  
  public void display(){
    fill(240);
    stroke(240);
    rect(x,y-12,300,15);
    textAlign(LEFT);
    fill(0);
    text("Module "+id,x,y);
    getData();
    int x = this.x;
    stroke(0);
    for(int i=0;i<8;i++){
      fill(checked[i]);
      ellipse(x+70, y-4, 12, 12);
      x+=20;
    }
    stroke(150);
    line(this.x,this.y+10,x+70,this.y+10);
    stroke(0);
    fill(255);
  }
  
  public int mouseover(){
    int i,x=this.x,h=12;
    for(i=0;i<8;i++){
      if(mouseX >= x+64 && mouseX <= x+76 && 
      mouseY >= y-h && mouseY <= y){
        fill(200);
        stroke(0);
        ellipse(x+70, y-4, 12, 12);
        clickx = x+70;
        return i;
      }
      display();
      x+=20;
    }
    return -1;
  }
  
  public boolean click(int index){
    if(checked[index] == 255){
      checked[index] = 75;
      return true;
    }else{
      checked[index] =255;
      return false;
    }
  
  }
  
  public int getData(){
   int data=0;
   for(int i =0;i<8;i++){
     if (checked[i]==75){
       data+=pow(2,i);
     }
   }
   text(hex(data,2),x+250,y);
   return data;
 }
 
  public void reset(){
    for(int i =0;i<8;i++){
     checked[i]=255;
   } 
  }

}
  public void settings() {  size(640, 360); }
  static public void main(String[] passedArgs) {
    String[] appletArgs = new String[] { "IHCcontroller" };
    if (passedArgs != null) {
      PApplet.main(concat(appletArgs, passedArgs));
    } else {
      PApplet.main(appletArgs);
    }
  }
}
