
#include <stdio.h>
//Global Variable declarations
float net;
float check;
float no;
float yes;
float DeductArr[10];

int Status;
int Type;
float Hours;
float Rate;
float hoursOT;
float NumOfDeduct;
float totDeductAmount;
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
float Calc (float hours, float rate ){
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
    //fixed rates from IRS website
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
//Function that calculates single biweekly
float CalcDeduction(float DeductArr[],float NumOfDeduct)
{
    float sum;
    if (NumOfDeduct ==0) return 0.0;
    for ( int i=0; i < NumOfDeduct; i++)
    {
        sum += DeductArr[i];
    }
    return sum;
}
void SingleBiweekly ( float Hours, float Rate) {
    float total;
    float gross= Calc (Hours, Rate);
    hoursOT=Hours-80.0;
    totDeductAmount=CalcDeduction(DeductArr,NumOfDeduct);
    //printf("%f:",totDeductAmount);
    if( Hours <= 80)
    {
        total= Calc (Hours, Rate);
    }
    else
    {
        total = (Calc( 80, Rate))+ (CalcOT(hoursOT,Rate));
    }
    
    if ( total > 146  && total < 519){
        no = calcSSMED(total);
        check= total - 146;
        yes = check * Percentage[0];
        net = total - (no+yes+totDeductAmount);
    }
    else if ( total > 519  && total < 1664){
        no = calcSSMED(total);
        check= total - 519.0;
        yes = check * Percentage[1];
        net = total - (no+yes+RateSumSingleBiweekly[1]+totDeductAmount);
    }
    else if ( total > 1664  && total< 3385){
        no = calcSSMED(total);
        check= total - 1664.0;
        yes = check *Percentage[2];
        net = total - (no+yes+RateSumSingleBiweekly[2]+totDeductAmount);
    }
    
    //printf("Your gross pay is: %.2f\n",gross);
    printf(" __________________________\n");
    printf("| Your net pay is: %.2f |\n",net);
    printf(" ---------------------------\n");
}


//Function that calculates net pay for
void SingleWeekly ( float Hours, float Rate) {
    float ans;
    hoursOT=Hours-40.0;
    totDeductAmount=CalcDeduction(DeductArr,NumOfDeduct);
   //printf("%f sds",totDeductAmount);
    if( Hours <= 40)
    {
        ans= Calc (Hours, Rate);
    }
    else
    {
        ans = (Calc( Hours, Rate))+ (CalcOT(hoursOT,Rate));
    }
    
        if ( ans > 73  && ans< 260 ){
            no = calcSSMED(ans);
            check= ans - 73;
            yes = check *Percentage[0];
            net = ans - (no+yes+totDeductAmount);
        }
        else if ( ans > 260  &&  ans < 832){
            no = calcSSMED(ans);
            check= ans - 260;
            yes = check *Percentage[1];
            net = ans - (no+yes+RateSumSingleWeekly[1]+totDeductAmount);
        }
        else if ( ans > 832 && ans< 1692){
            no = calcSSMED(ans);
            check= ans - 1664;
            yes = check * Percentage[2];
            net = ans - (no+yes+RateSumSingleWeekly[2]+totDeductAmount);
        }
    
    printf(" __________________________\n");
    printf("| Your net pay is: %.2f |\n",net);
    printf(" ---------------------------\n");
    }
    

void MarriedWeekly ( float Hours, float Rate)
{
    float ans;
    hoursOT=Hours-40.0;
    totDeductAmount=CalcDeduction(DeductArr,NumOfDeduct);
    if( Hours <= 40)
    {
        ans= Calc (Hours, Rate);
    }
    else
    {
        ans = (Calc( Hours, Rate))+ (CalcOT(hoursOT,Rate));
    }
    
    if ( ans > 73  && ans< 260 ){
        no = calcSSMED(ans);
        check= ans - 73;
        yes = check *Percentage[0];
        net = ans - (no+yes+totDeductAmount);
    }
    else if ( ans > 260  &&  ans < 832){
        no = calcSSMED(ans);
        check= ans - 260;
        yes = check *Percentage[1];
        net = ans - (no+yes+RateSumMarWeekly[1]+totDeductAmount);
    }
    else if ( ans > 832 && ans< 1692){
        no = calcSSMED(ans);
        check= ans - 1664;
        yes = check * Percentage[2];
        net = ans - (no+yes+RateSumMarWeekly[2]+totDeductAmount);
    }
    
    printf(" __________________________\n");
    printf("| Your net pay is: %.2f |\n",net);
    printf(" ---------------------------\n");
    
}

void MarriedBiweekly( float Hours, float Rate)
{
    float total;
    float gross= Calc (Hours, Rate);
    hoursOT=Hours-80.0;
    totDeductAmount=CalcDeduction(DeductArr,NumOfDeduct);
    if( Hours <= 80)
    {
        total= Calc (Hours, Rate);
    }
    else
    {
        total = (Calc( 80, Rate))+ (CalcOT(hoursOT,Rate));
    }
    
    if ( total > 146  && total < 519){
        no = calcSSMED(total);
        check= total - 146;
        yes = check * Percentage[0];
        net = total - (no+yes+totDeductAmount);
    }
    else if ( total > 519  && total < 1664){
        no = calcSSMED(total);
        check= total - 519.0;
        yes = check * Percentage[1];
        net = total - (no+yes+RateSumMarBiweekly[1]+totDeductAmount);
    }
    else if ( total > 1664  && total< 3385){
        no = calcSSMED(total);
        check= total - 1664.0;
        yes = check *Percentage[2];
        net = total - (no+yes+RateSumMarBiweekly[2]+totDeductAmount);
    }
    
    //printf("Your gross pay is: %.2f\n",gross);
    printf(" __________________________\n");
    printf("| Your net pay is: %.2f |\n",net);
    printf(" ---------------------------\n");
}
                         
                        


int main(){
    
    
    // User Input
    int i;
    printf("________________________________________\n\n");
    printf("PRESS 1 for Single  Press 2 For married ");
    scanf("%d",&Status);
    printf("__________________________________________\n\n");
    printf("Press 1 for weekly.. Press 2 for biweekly ");
    scanf("%d",&Type);
    printf("Please enter the number of deductions you have: \n");
    scanf("%f",&NumOfDeduct);
    if( NumOfDeduct!=0){
        
    printf("For each deduction enter the amount in dollars.\n");
    }
    for(i=0;i<NumOfDeduct;i++)
    {
        printf("Deduction %d: ",i+1 );
        scanf("%f",&DeductArr[i]);
        
    }
    printf("Enter rate: ");
    scanf("%f",&Rate);
    printf("Enter hours worked: ");
    scanf("%f",&Hours);
   // totDeductAmount=CalcDeduction(DeductArr,NumOfDeduct);
    //printf("ISSS %f",totDeductAmount);
    switch (Status) {
        //Single
        case 1 :
            if(Type== 2){
            SingleBiweekly( Hours, Rate);
            break;
            }
            else
            SingleWeekly(Hours, Rate);
            break;
            
        //Married
        case 2 :
            if(Type==2)
            {
            MarriedWeekly ( Hours, Rate);
            break;
            }
            MarriedBiweekly( Hours, Rate);
            break;
    }
    
    
   
    
    
    
    
}
