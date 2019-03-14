class Module{
  int x,y,id;
  int[] checked={255,255,255,255,255,255,255,255 };
  int clickx = 0;
  Module(int x,int y,int id){
    this.x=x;
    this.y=y;
    this.id=id;
    
  }
  
  void display(){
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
  
  int mouseover(){
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
  
  boolean click(int index){
    if(checked[index] == 255){
      checked[index] = 75;
      return true;
    }else{
      checked[index] =255;
      return false;
    }
  
  }
  
  int getData(){
   int data=0;
   for(int i =0;i<8;i++){
     if (checked[i]==75){
       data+=pow(2,i);
     }
   }
   text(hex(data,2),x+250,y);
   return data;
 }
 
  void reset(){
    for(int i =0;i<8;i++){
     checked[i]=255;
   } 
  }

}
