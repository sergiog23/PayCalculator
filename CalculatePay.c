#include <stdio.h>
//Global Variable declarations
float net;
float check;
float no;
float yes;

int Status;
int Type;
float Hours;
float Rate;
float hoursOT;
//Declaration of Constant rates pulled from IRS 2019 Publication 15

float Percentage[] = {0.10,0.12,0.22,0.24,0.32,0.35};

// Single and Biweekly
float RateSumSingleBiweekly[] = {0.0, 37.30, 174.70, 553.32, 1259.64, 1793.40};

//Single and weekly
float RateSumSingleWeekly[] = {0.0, 18.70, 87.34, 276.54, 629.82, 896.70};

//Married and Biweekly
float RateSumMarBiweekly[] = {0.0,74.60,349.40, 1106.42, 2519.06,3586.90};

//Married and Weekly
float RateSumMarWeekly[] = {0.0,37.30,174.70,553.10,1259.66,1793.42};


//Function to Calculate gross check
float Calc (int hours, int rate ){
    float gross;
    gross= hours *rate;
    return gross;
}
//Function to calculate OT Rate
float CalcOT( float hours, float rate){
    float  OTrate=rate*1.5;
    float nose;
    nose = OTrate*hours;
    
    return nose;
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
//Function to calculate 401k Deductions
// Takes in the gross payment and the percentage of 401k
float Calc401k( float gross, float Percentage){
    
    float deduction= gross * (Percentage * 0.01);
    return deduction;
}
//Function that calculates net pay for Single person getting paid biweekly
void SingleBiweekly ( float Hours, float Rate) {
    
    if( Hours <= 80)
    {
        float ans= Calc (Hours, Rate);
        
        if ( ans > 146  && ans< 519){
            no = calcSSMED(ans);
            check= ans - 146;
            yes = check *Percentage[0];
            net = ans - (no+yes);
        }
        else if ( ans > 519  &&  ans < 1664){
            no = calcSSMED(ans);
            check= ans - 519;
            yes = check *Percentage[1];
            net = ans - (no+yes+RateSumSingleBiweekly[1]);
        }
        else if ( ans > 1664  && ans< 3385){
            no = calcSSMED(ans);
            check= ans - 1664;
            yes = check * Percentage[2];
            net = ans - (no+yes+RateSumSingleBiweekly[2]);
        }
            printf("Your net pay is: %.2f\n",net);
    }
    else
    {
        hoursOT=Hours-80.0;
        float OT= CalcOT(hoursOT,Rate);
        float Regular= Calc(80, Rate);
        float total= OT + Regular;
    
        if ( total > 146  && total < 519){
            no = calcSSMED(total);
            check= total - 146;
            yes = check * Percentage[0];
            net = total - (no+yes);
        }
        else if ( total > 519  && total < 1664){
            no = calcSSMED(total);
            check= total - 519;
            yes = check * Percentage[1];
            net = total - (no+yes+RateSumSingleBiweekly[1]);
        }
        else if ( total > 1664  && total< 3385){
            no = calcSSMED(total);
            check= total - 1664.0;
            yes = check *Percentage[2];
            net = total - (no+yes+RateSumSingleBiweekly[2]);
        }
        printf("your net pay is: %.2f\n",net);
        
    }
    
    
}
//Function that calculates net pay for
void SingleWeekly ( float Hours, float Rate) {
    
     hoursOT=Hours-40.0;
    
    if( Hours <= 40)
    {
        float ans= Calc (Hours, Rate);
    }
    else
    {
        float ans = (Calc( Hours, Rate))+ (CalcOT(hoursOT,Rate));
    }
        if ( ans > 73  && ans< 260 ){
            no = calcSSMED(ans);
            check= ans - 73;
            yes = check *Percentage[0];
            net = ans - (no+yes);
        }
        else if ( ans > 260  &&  ans < 832){
            no = calcSSMED(ans);
            check= ans - 260;
            yes = check *Percentage[1];
            net = ans - (no+yes+RateSumSingleWeekly[1]);
        }
        else if ( ans > 832 && ans< 1692){
            no = calcSSMED(ans);
            check= ans - 1664;
            yes = check * Percentage[2];
            net = ans - (no+yes+RateSumSingleWeekly[2]);
        }
    }

        printf("Your net pay is: %.2f\n",net);
        
    }
    
    
}
                         
float Married ( float Hours, float Rate)
{
    
    return 0.0;
}
                         
                        


int main(){
    
    
    // User Input
    printf("PRESS 1 for Single .. Press 2 For married ");
    scanf("%d",&Status);
    
    printf("Press 1 for weekly.. Press 2 for biweekly ");
    scanf("%d",&Type);
    
    printf("Enter rate: ");
    scanf("%f",&Rate);
    printf("Enter hours worked: ");
    scanf("%f",&Hours);
    
    switch (Status) {
        //Single
        case 1 :
            if(Type== 2){
          SingleBiweekly( Hours, Rate);
                break;
            }
            else
          Si
            break;
        //Married
        case 2 :
            Married ( Hours, Rate);
            
            break;
    }
    
    
   
    
    
    
    
}
