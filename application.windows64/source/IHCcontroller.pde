
import processing.serial.*;
btn btnConect;
Module[] mdl = new Module[8];
Serial myPort;
String log = "";
boolean conected=false;

void setup() {
  size(640, 360);
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

void draw() {
   btnConect.mouseover();
   printlog();
   for(int i=0 ; i<8; i++){
    mdl[i].mouseover();
   }
}

void printlog(){
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

void mousePressed() {
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

void serialEvent(Serial p) { 
  log += p.readString();
  conected=true;
}
