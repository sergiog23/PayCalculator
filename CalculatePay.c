#include <stdio.h> 

//Declaration of Constant rates pulled from IRS 2019 Publication 156

// Single and Biweekly
float RateSumSingleBiweekly[] = {0.0, 37.30, 174.70, 553.32, 1259.64, 1793.40};
float PercentageSingleBiweekly[] = {0.10,0.12,0.22,0.24,0.32,0.35};

//Single and weekly
float RateSumSingleWeekly[] = {0.0, 18.70, 87.34, 276.54, 629.82, 896.70};
float PercentageSingleWeekly[] = {0.10,0.12,0.22,0.24,0.32,0.35};

//Married and Biweekly 
float RateSumMarBiweekly[] = {0.0,74.60,349.40, 1106.42, 2519.06,3586.90};
float PercentageMarBiweekly[] = {0.10,0.12,0.22,0.24,0.32,0.35};

//Married and Weekly
float RateSumMarWeekly[] = {0.0,37.30,174.70,553.10,1259.66,1793.42};
float PercentageMarWeekly[] = {0.10,0.12,0.22,0.24,0.32,0.35};

//Function to Calculate gross check
float Calc (int hours, int rate ){
float gross;
gross= hours *rate;
return gross;
}

float CalcOT( float hours, float rate){
float  OTrate=rate*1.5;
float nose; 
nose = OTrate*hours;

return nose;
}
float Single ( float Hours, float Rate) {
	
	if( Hours <= 80)
  {
	float ans= Calc (Hours, Rate);

	if ( ans > 146  && ans< 519){
	no = calcSSMED(ans);
        check= ans - 146;
        yes = check *.10;
        net = ans - (no+yes);	
	}
      else if ( ans > 519  &&  ans< 1664){
          no = calcSSMED(ans);
          check= ans - 519;
          yes = check *.12;
          
          net = ans - (no+yes+que);
      }
      else if ( ans > 1664  && ans< 3385){
          no = calcSSMED(ans);
          check= ans - 1664;
          yes = check *.12;
          
          net = ans - (no+yes+rich);
          //printf("your net pay is: %f\n",&net);
      }
  }
 else 
 {
   hoursOT=Hours-80.0;
   float OT= CalcOT(hoursOT,Rate);
   float Regular= Calc(80, Rate);
   float total= OT + Regular;
     //printf("OT %f",OT);
     //printf("Regular %f",Regular);
     //printf("Total : %f" ,total);
     if ( total > 146  && total < 519){
         no = calcSSMED(total);
         check= total - 146;
         yes = check *.10;
         net = total - (no+yes);
     }
     else if ( total > 519  && total < 1664){
         no = calcSSMED(total);
         check= total - 519;
         yes = check *.12;
         
         net = total - (no+yes+que);
     }
     else if ( total > 1664  && total< 3385){
         no = calcSSMED(total);
         check= total - 1664.0;
         yes = check *.22;
        // printf("check %f" yes);
         
         net = total - (no+yes+rich);
         printf(" your gross pay is %.2f\n",total);
         printf("your net pay is: %.2f\n",net);
     }
     
     
 }

	
}

//function to calculate SSN and medicare
float calcSSMED( float gross)
{
float SS= 0.0145;
float Med= 0.062;
float sum; 
sum = (gross*SS)+(gross*Med);
return sum; 

}
int main(){
	

float One = 0.1;
float Two = 0.12;
float Three= 0.22;
float Four= 0.24;
float Five= 0.32;
float SS= 0.0145;
float med= 0.062;
float net;
float check;
float no;
float yes;

int Status;
int Type;
float Hours;
int Rate;
float hoursOT;
float que = 37.30;
float rich= 174.70;

printf("PRESS 1 for SINGLE.. 2 For married ");
scanf("%d",&Status);

printf("Press 1 for weekly.. 2 for biweekly ");
scanf("%d",&Type);
    
printf("Enter rate: ");
scanf("%d",&Rate);
printf("Enter hours worked: ");
scanf("%f",&Hours);



//SINGLE and Paid biweekly

 if( Hours <= 80)
  {
	float ans= Calc (Hours, Rate);

	if ( ans > 146  && ans< 519){
	no = calcSSMED(ans);
        check= ans - 146;
        yes = check *.10;
        net = ans - (no+yes);	
	}
      else if ( ans > 519  &&  ans< 1664){
          no = calcSSMED(ans);
          check= ans - 519;
          yes = check *.12;
          
          net = ans - (no+yes+que);
      }
      else if ( ans > 1664  && ans< 3385){
          no = calcSSMED(ans);
          check= ans - 1664;
          yes = check *.12;
          
          net = ans - (no+yes+rich);
          //printf("your net pay is: %f\n",&net);
      }
  }
 else 
 {
   hoursOT=Hours-80.0;
   float OT= CalcOT(hoursOT,Rate);
   float Regular= Calc(80, Rate);
   float total= OT + Regular;
     //printf("OT %f",OT);
     //printf("Regular %f",Regular);
     //printf("Total : %f" ,total);
     if ( total > 146  && total < 519){
         no = calcSSMED(total);
         check= total - 146;
         yes = check *.10;
         net = total - (no+yes);
     }
     else if ( total > 519  && total < 1664){
         no = calcSSMED(total);
         check= total - 519;
         yes = check *.12;
         
         net = total - (no+yes+que);
     }
     else if ( total > 1664  && total< 3385){
         no = calcSSMED(total);
         check= total - 1664.0;
         yes = check *.22;
        // printf("check %f" yes);
         
         net = total - (no+yes+rich);
         printf(" your gross pay is %.2f\n",total);
         printf("your net pay is: %.2f\n",net);
     }
     
     
 }

    


}
