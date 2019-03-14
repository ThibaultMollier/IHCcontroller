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
  
  void display(){
    fill(red,green,blue);
    rect(x,y,w,h);
    textAlign(CENTER);
    fill(0);
    text(txt,txtx,txty);
  }
  
  boolean mouseover(){
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
  
  boolean click(){
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
