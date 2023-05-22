#include <iostream>
#include <cmath>
#include <string>
#include <stdlib.h>
using namespace std;

struct Fields
{
int age;
string gender;
double height;
double weight;
int act_type;
double act_level[5];
double time;
string username;
double bmi;
double bfp;
double bmr;
double calburn;
double ibw;
double lbm;
double hw;
double a[][2];
};
struct Fields u;

void bmi()
{
  string bmi_res="";
  double h=u.height/100;
  double bmi=u.weight/(h*h);
  if(u.age>=20)
  {
    if(bmi<=16)
    bmi_res="Severe Thinness";
  else if(16<bmi && bmi<=17)
    bmi_res="Moderate Thinness";
  else if(17<bmi && bmi<=18.5)
    bmi_res="Mild Thinness";
  else if(18.5<bmi && bmi<=25)
    bmi_res="Normal";
  else if(25<bmi && bmi<=30)
    bmi_res="overweight";
  else if(30<bmi && bmi<=35)
    bmi_res="Obese Class I";
  else if(35<bmi && bmi<=40)
    bmi_res="Obese Class II";
  else if(bmi>40)
    bmi_res="Obese Class III";
  }
  else if(2<u.age<20)
  {
    if(bmi<5)
    bmi_res="Underweight";
    else if(5<=bmi && bmi<=85)
    bmi_res="Healthy weight";
    else if(35<85 && bmi<=95)
    bmi_res="At risk of overweight";
    else if(bmi>95)
    bmi_res="Overweight";
    else if(bmi>40)
    bmi_res="Wrong information";
  }
  cout<<"BMI of "<<u.username<<" is :         "<<bmi<<"\t\t";
  u.bmi=bmi;
  cout<< bmi_res<<endl;
}

void bmr()
{
  double BMR;
    if (u.gender=="male")
     BMR = 88.362 + (13.397 * u.weight) + (4.799 * u.height) - (5.677 * u.age);
    else if (u.gender=="female")
     BMR = 47.593 + (9.247 * u.weight) + (3.098 * u.height) - (4.330 * u.age);
  cout<<"BMR of "<<u.username<<" is :         "<<BMR<<endl;
  u.bmr=BMR;
}

void bfp()
{
  double BFP;
  double h=u.height/100;
  double bmi=u.weight/(h*h);
  u.bmi=bmi;
    if (u.gender=="male")
        BFP = (1.20 * u.bmi) + (0.23 * u.age) - 16.2;
    else if (u.gender=="female")
        BFP = (1.20 * u.bmi) + (0.23 * u.age) - 5.4;
    cout<<"BFP of "<<u.username<<" is :         "<<BFP<<endl;
  u.bfp=BFP;
}

void calburn()
{
  cout<<"Enter the corresponding number according to your activity type\n"<<endl ;
  cout<<"1. Person who does Little to no exercise"<<endl;
  cout<<"2. A slightly active person who does light exercise 1–3 days a week"<<endl;
  cout<<"3. A moderately active person who performs moderate exercise 3–5 days a week"<<endl;
  cout<<"4. A very active person who exercises hard 6–7 days a week"<<endl;
  cout<<"5. An extra active person who either has a physically demanding job or has a particularly challenging exercise routine\n"<<endl;
  cin>>u.act_type;
  u.act_level[0]=1.2;
  u.act_level[1]=1.37;
  u.act_level[2]=1.55;
  u.act_level[3]=1.725;
  u.act_level[4]=1.9;
  double cal;
  if(1<=u.act_type && u.act_type<=5)
  {
    cout<<"\nEnter the amount if time you did activity for (in minutes)\n"<<endl;
    cin>>u.time;
      if(u.gender=="male")
      {
        u.bmr = 88.362 + (13.397 * u.weight) + (4.799 * u.height) - (5.677 * u.age);
        cal= u.bmr*u.act_level[u.act_type-1];
      }
    else if(u.gender=="female")
    {
      u.bmr= 47.593 + (9.247 * u.weight) + (3.098 * u.height) - (4.330 * u.age);
      cal= u.bmr*u.act_level[u.act_type-1];
    }
    cout<<"\n"<<u.username<<" burns : "<<cal<<" calories on a typical day"<<endl;
    cout<<"\nRemember that this estimate is based on your body weight, height, age, gender, and your average level of activity.\nOn active days, you'll need more calories, so it's okay to eat a little more than you would on an average day. But on more sedentary days, you may want to reduce your calorie intake."<<endl;
    u.calburn=cal;
  }
  else
  cout<<"activity type does not match\n"<<endl;
}
void idealw_dis(double r,double m, double d, double h);
void idealw(double height,int age,string gender)
{
  double robinson,miller,hamwi,devine;
  if(gender=="male")
  {
    robinson=52+ 1.9*(int)((u.height-152.4)/2.54);
    miller=56.2+ 1.41*(int)((u.height-152.4)/2.54);
    devine=50+ 2.3*(int)((u.height-152.4)/2.54);
    hamwi=48+ 2.7*(int)((u.height-152.4)/2.54);
    u.ibw=(robinson+miller+devine+hamwi)/4;
    idealw_dis(robinson,miller,devine,hamwi);
  }
  else if(gender=="female")
  {
    robinson=49+ 1.7*(int)((height-152.4)/2.54);
    miller=53+ 1.36*(int)((height-152.4)/2.54);
    devine=45.5+ 2.3*(int)((height-152.4)/2.54);
    hamwi=45.5+ 2.2*(int)((height-152.4)/2.54);
    u.ibw=(robinson+miller+devine+hamwi)/4;
    idealw_dis(robinson,miller,devine,hamwi);
  }
  else
    cout<<"wrong entry"<<endl;
}
 void idealw_dis(double r,double m, double d, double h)
{
  cout<<"Robinson IBW is:\t"<<r<<endl;
  cout<<"Miller IBW is:  \t"<<m<<endl;
  cout<<"Devine IBW is:  \t"<<d<<endl;
  cout<<"Hamwi IBW is:   \t"<<h<<endl;
  cout<<"\nHence mean IBW: \t"<<u.ibw<<endl;
}

void lbm_dis(double b,double j, double h);
void lbm(double weight,double height,int age,string gender)
{
  double boer,james,hume;
  if(age>14)
  {
      if(gender=="male")
  {
    boer=0.407*weight + 0.267*height - 19.2;
    james=1.1*weight- 128*pow((weight/height),2);
    hume=0.32810*weight + 0.33929*height - 29.5336;
    u.lbm=(boer+james+hume)/3;
    lbm_dis(boer,james,hume);
  }
  else if(gender=="female")
  {
    boer=0.252*weight + 0.473*height - 48.3;
    james=1.07*weight- 148*pow((weight/height),2);
    hume=0.29569*weight + 0.41813*height - 43.2933;
    u.lbm=(boer+james+hume)/3;
    lbm_dis(boer,james,hume);
  }
    else
    cout<<"wrong entry"<<endl;
  }
  else if(age<=14)
  {
    double ecv=0.0215*pow(weight,0.6469)*pow(height,0.7236);
    double lbm=3.8*ecv;
    cout<<"LBM for kids aged 14 or younger is:\t"<<lbm<<endl;
    u.lbm=lbm;
  }
  else
    cout<<"wrong entry"<<endl;
}
void lbm_dis(double b,double j, double h)
{
  cout<<"Boer LBM is:         \t"<<b<<endl;
  cout<<"James LBM is:        \t"<<j<<endl;
  cout<<"Hume LBM is:         \t"<<h<<endl;
  cout<<"\nHence mean LBM is: \t"<<u.lbm<<endl;
}

void display_1()
{
    cout<<"\n\nWelcome To The Health Calculator !!\nPlease enter the following details :D\n"<<endl;
    cout<<"1. Username \n2. Age \n3. Gender (male or female) (please write in the exact word) \n\n";
    //cout<<"If you do not have your details in the units required, feel free to use our units convertor ! It will automatically save your details in the required unit !!"<<endl;
    cin>>u.username>>u.age>>u.gender;
    int ch;
    double f,i,p;
    while(1)
    {
    cout << "\nEnter height\n" << endl;
    cout << "Type 1. if input is in centimeters \n     2. if input is in feet'inches\n"<<endl;
    cin >> ch;
    if (ch==2)
    {
        cout << "\nEnter Feet" << endl;
        cin >> f;
        cout << "Enter Inches" << endl;
        cin >> i;
        u.height = (f * 30.48) + (i * 2.54);
        break;
    }

    else if (ch==1)
    {
        cout << "\nEnter Centimeters" << endl;
        cin >> u.height;
        break;
    }
    else 
      cout<<"\nWrong input"<<endl;
      continue;
    }
    while(1)
    {
    cout << "\nEnter weight\n" << endl;
    cout << "Type 1. If input is in kilograms \n     2. If input is in pounds\n"<<endl;
    cin >> ch;
    if (ch==2)
    {
        cout << "\nEnter pounds" << endl;
        cin >> p;
        u.weight = p / 2.205;
        break;
    }

    else if (ch==1)
    {
        cout << "\nEnter Kilograms" << endl;
        cin >> u.weight;
        break;
    }
    else 
      cout<<"\nWrong input"<<endl;
      continue;
    }
}

 int choice()
{
    int choice;
    cout<<"\nEnter the number of the field you want to calculate : "<<endl;
    cout<<"1. BMI \n2. Calories burned \n3. Body Fat \n4. BMR \n5. Ideal Weight \n6. Lean Body Mass \n";
    cin>>choice;
    return choice;
}
void display_2()
{ //dowhike loop here
int c;char ch;
cout<<"\nHere is an overview of the terms"<<endl;
cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
cout<<"\n1. BMI Body Mass Index is a measurement of a person's leanness or corpulence based on their height and weight, and is intended to quantify tissue mass.\nIt is widely used as a general indicator of whether a person has a healthy body weight for their height.\nSpecifically, the value obtained from the calculation of BMI is used to categorize whether a person is underweight, normal weight, overweight, or obese depending on what range the value falls between."<<endl;
cout<<"\n2. Calories Burned displays the number of calories the user uses up on a typical day while taking into account the kind of activity they do"<<endl;
cout<<"\n3. BMR Basal Metabolic Rate is the amount of energy needed while resting in a temperate environment when the digestive system is inactive."<<endl;
cout<<"\n4. BFP Body fat percentage is the percentage of your weight that is made up of fat.\nIt consists of both storage body fat and essential body fat. "<<endl;
cout<<"\n5. IBW Ideal Body Weight computes IBW ranges based on height, gender, and age.\nIt was actually introduced to estimate dosages for medical use, and the formulas that calculate it are not at all related to how a person looks at a given weight.\nIt has since been determined that the metabolism of certain drugs is more based on IBW than it is total body weight."<<endl;
cout<<"\n6. LBM Lean Body Mass is a part of body composition that is defined as the difference between total body weight and body fat weight.\nThis means that it counts the mass of all organs except body fat, including bones, muscles, blood, skin, and everything else."<<endl;
cout<<"\n---------------------------------------------------------------------------------------------------------------------------------------------------------\n"<<endl;
  do
    {
      cout<<"---------------------------------------------------------------------------------------------------------------------------------------------------------\n";
      cout<<"\nEnter the number of the field you want to calculate : "<<endl;
    cout<<"\n1. BMI \n2. Calories Burned \n3. BMR \n4. BFP \n5. Ideal Weight \n6. Lean Body Mass \n"<<endl;
    cout<<"Or else press 0 to exit choice window\n"<<endl;
    cin>>c;
    cout<<"\n";
    if(c==1)
    {
      u.a[0][0]=0;
      bmi();
      u.a[0][0]++;
      u.a[0][1]=u.bmi;
    }
    else if (c==2)
    {
      u.a[1][0]=0;
      calburn();
      u.a[1][0]++;
      u.a[1][1]=u.calburn;

    }
    else if(c==3)
    {
      u.a[2][0]=0;
      bmr();
      u.a[2][0]++;
      u.a[2][1]=u.bmr;
    }
    else if(c==4)
    {
      u.a[3][0]=0;
      bfp();
      u.a[3][0]++;
      u.a[3][1]=u.bfp;
    }
    else if(c==5)
    {
      u.a[4][0]=0;
      idealw(u.height,u.age,u.gender);
      u.a[4][0]++;
      u.a[4][1]=u.ibw;
    }
    else if(c==6)
    {
      u.a[5][0]=0;
      lbm(u.weight,u.height,u.age,u.gender);
      u.a[5][0]++;
      u.a[5][1]=u.lbm;
    }
    else if(c==0)
    break;
    else
    {
      cout<<"\nYou have entered the wrong option, enter 'y' to go back and choose again or 'n' to exit\n"<<endl;
      cin>>ch;
      if(ch=='y')
      continue;
      else
      break;
    }
    }while(c!=0);
}

void report()
{
  cout<<"\nPlease wait while your report is being made !\n"<<endl;
  for(int j=10;j<=100;j=j+10)
    {
        for(int k=1;k<=j/10;k++)
        cout<<"[] ";
        cout<<j<<" %"<<" Loading";
        cout<<"\r";
    for(int  i=0;i<150000000;i++)
    {
    }
    cout<<"\r";
    }
  int l=0;
  l=u.a[0][0]+u.a[1][0]+u.a[2][0]+u.a[3][0]+u.a[4][0]+u.a[5][0];
    cout<<"*****************************************************************\n";
    cout<<"                                                                 \n";
    cout<<" Patient Details\n";
    cout<<"_________________________________________________________________\n";
    cout<<" Name   : "<<u.username<<endl;
    cout<<" Age    : "<<u.age<<endl;
    cout<<" Gender : "<<u.gender<<endl;
    cout<<" Height : "<<u.height<<" cms"<<endl;
    cout<<" Weight : "<<u.weight<<"kgs"<<endl;
    cout<<"_________________________________________________________________\n";
    cout<<"-----------------------------------------------------------------\n";
  
   for(int i=0;i<6;i++)
    {
        if(u.a[i][0]==1)
        {
          if(i==0)
        {
            cout<<" BMI : "<<u.a[i][1]<<endl;
            cout<<"_________________________________________________________________\n";
        }
        else if(i==1)
        {
            cout<<" Calories required to keep healthy weight : "<<u.a[i][1]<<" calories"<<endl;
             cout<<"_________________________________________________________________\n";
        }
        else if(i==2)
        {
            cout<<" BMR : "<<u.a[i][1]<<endl;
             cout<<"_________________________________________________________________\n";
        }
        else if(i==3)
        {
            cout<<" BFP : "<<u.a[i][1]<<endl;
             cout<<"_________________________________________________________________\n";
        }
        else if(i==4)
        {
            cout<<" IBW : "<<u.a[i][1]<<" kgs"<<endl;
             cout<<"_________________________________________________________________\n";
        }
        else if(i==5)
        {
            cout<<" LBM : "<<u.a[i][1]<<endl;
            cout<<"_________________________________________________________________\n";
        }
        }
        
    }
    cout<<"Please visit us again !!\n";
    cout<<" \n";
    cout<<"*****************************************************************\n";
   
}

void repchoice()
{
  cout<<"Enter 'y' if you need a report else enter 'n'\n"<<endl;
  char cho;
  cin>>cho;
  if (cho=='y')
  report();
  else 
  cout<<"It has been great having you here, Enjoy your day and visit us again !!"<<endl;
}

int main() 
{
  system("Color B1");
 display_1();
 display_2();
 repchoice();
}
