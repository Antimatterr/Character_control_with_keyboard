#include<iostream>
#include<conio.h>
using namespace std;
const int width = 30;
const int height = 40;
int x,y;
enum edirection{STOP = 0,LEFT,RIGHT,UP,DOWN};
edirection dir;
bool gameover;
int obx,oby;
void setup()
{ 
  gameover = false;
  dir = STOP;
  x = width/2;
  y = height/2;
}
void draw()
{
  system("cls");
  for (int i = 0; i < width+1; i++)
  cout<<"$";
  cout<<endl;

  for( int i = 0;i<height;i++ )
  {
    for(int j = 0;j<width ;j++)
    {
      if(j == obx && i == oby)
      cout<<"#";     

      if(j == 0)
      cout<<"$";
      else
      cout<<" ";

      if(i == y && j == x)
      cout<<"+";

    if(j == width - 1)
      cout<<"$";
    }
    cout<<endl;
  }
  cout<<"$";
  cout<<endl;

for(int i=0;i<width+1;i++)
cout<<"$";
cout<<endl;
}
  
void input()
{
  if(_kbhit())
   {
     switch(_getch())
     {
       case 'a':
       dir = LEFT;
       break;
       case 'd':
       dir = RIGHT;
       break;
       case 's':
       dir = DOWN;
       break;
       case 'w':
       dir = UP;
       break;
       case 'x':
       gameover = true;
       break;
     }
   }
}
void logic()
{
  switch(dir)
  {
    case  STOP:
    break;
    case LEFT:
    x--;
    break;
  case RIGHT:
  x++;
  break;
  case UP:
  y--;
  break;
  case DOWN:
  y++;
  break;
  }
}
int main()
{ 
  setup();
  while(!gameover)
  {
    draw();
    input();
    logic(); 
  }
  return 0;
}