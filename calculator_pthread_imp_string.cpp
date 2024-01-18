#include<iostream>
#include<cstring>
#include<cmath>
#include<string>
#include<pthread.h>

double result = 0;
pthread_mutex_t m1;
int base;
void *add_fun(void *arg);
void *sub_fun(void *arg);
void *mul_fun(void *arg);
void *div_fun(void *arg);
void *mod_fun(void *arg);
void *pow_fun(void *arg);
void *log_fun(void *arg);
void *sin_fun(void *arg);
void *cos_fun(void *arg);
void *sec_fun(void *arg);
void *tan_fun(void *arg);
using namespace std;

int main() {
    pthread_t add, sub, mul, div, mod, pow,sin,cos,tan,log,sec;
    string op;
    double num;


    cout << "Choose operator to perform operation\n"
            "'x' terminate\n"
            " + add\n"
            " - sub\n"
            " * mul\n"
            " % moddivison\n"
            " / division\n"
            " p powervalue\n"
            " = result\n"
            " sin sin\n"
            " cos cos\n"
            " tan tan\n"
            "sec sec\n"
            "log logvalue\n"
            "k clear\n";

    while (1) 
    {
        cout << "Enter the operator : ";
        cin >> op;

        if (op == "x" || op == "X") 
        {
            break;
        } 
        else if(op!="p" && op!="P" && op!="log" && op!="Log" && op!="=" && op!="k" && op!="K" && op!="sin" && op!="Sin" && op!="cos" && op!="Cos" && op!="tan" && op!="Tan"&&op!="Sec"&&op!="sec")
        {
            cout << "Enter the num : ";
            cin >> num;
        }

         if (op == "+") 
         {
            pthread_create(&add, NULL, add_fun, (void *)&num);
            pthread_join(add, NULL);
         } 
        else if (op == "-") 
        {
            pthread_create(&sub, NULL, sub_fun, (void *)&num);
            pthread_join(sub, NULL);
        } 
        else if (op == "*") 
        {
            pthread_create(&mul, NULL, mul_fun, (void *)&num);
            pthread_join(mul, NULL);
        } 
        else if (op == "/") 
        {
            pthread_create(&div, NULL, div_fun, (void *)&num);
            pthread_join(div, NULL);
        } 
        else if (op == "%") 
        {
            pthread_create(&mod, NULL, mod_fun, (void *)&num);
            pthread_join(mod, NULL);
        } 
        else if (op == "p") 
        {
            pthread_create(&pow, NULL, pow_fun, (void *)&num);
            pthread_join(pow, NULL);
        } 
        else if (op == "=") 
        {
            
            cout << "Result : " << result << endl;
            
        } 
        else if (op == "k" || op == "K") 
        {
            result = 0;
        }
        else if (op=="sin"||op=="Sin")
        {
        
        	pthread_create(&sin, NULL, sin_fun, (void *)&num);
            	pthread_join(sin, NULL);
        
        }
        else if (op=="cos"||op=="Cos")
        {
        
        	pthread_create(&cos, NULL, cos_fun, (void *)&num);
            	pthread_join(cos, NULL);
        
        }
        else if (op=="tan"||op=="Tan")
        {
        
        	pthread_create(&tan, NULL, tan_fun, (void *)&num);
            	pthread_join(tan, NULL);
        
        }
        else if (op=="Sec"||op=="sec")
        {
        
        	pthread_create(&sec, NULL, sec_fun, (void *)&num);
            	pthread_join(sec, NULL);
        
        }
        else if (op=="log"||op=="Log")
        {
        
        	pthread_create(&log, NULL, log_fun, (void *)&num);
            	pthread_join(log, NULL);
        
        }
    }

    pthread_mutex_destroy(&m1);

    return 0;
}

void *add_fun(void *arg) 
{
    double *num_ptr = (double *)arg;

    pthread_mutex_lock(&m1);
    result += *num_ptr;
    pthread_mutex_unlock(&m1);

    pthread_exit(NULL);
}

void *sub_fun(void *arg) 
{
    double *num_ptr = (double *)arg;

    pthread_mutex_lock(&m1);
    result -= *num_ptr;
    pthread_mutex_unlock(&m1);

    pthread_exit(NULL);
}

void *mul_fun(void *arg) 
{
    double *num_ptr = (double *)arg;

    pthread_mutex_lock(&m1);
    result *= *num_ptr;
    pthread_mutex_unlock(&m1);

    pthread_exit(NULL);
}

void *div_fun(void *arg) 
{
    double *num_ptr = (double *)arg;

    pthread_mutex_lock(&m1);
    if (*num_ptr != 0) {
        result /= *num_ptr;
    } else {
        cout << "Error: Division by zero\n";
    }
    pthread_mutex_unlock(&m1);

    pthread_exit(NULL);
}

void *mod_fun(void *arg) 
{
    double *num_ptr = (double *)arg;

    pthread_mutex_lock(&m1);
    if (*num_ptr != 0) 
    {
        result = fmod(result, *num_ptr);
    } 
    else 
    {
        cout << "Error: Modulo by zero\n";
    }
    pthread_mutex_unlock(&m1);

    pthread_exit(NULL);
}

void *pow_fun(void *arg) 
{
    double *num_ptr = (double *)arg;
    pthread_mutex_lock(&m1);
    int power;
    cout << "Enter the power value : ";
    cin >> power;
    double tempResult = result;
    if (power == 0) 
    {
        result = 1; 
    } 
    else if (power > 0) 
    {
        for (int i = 1; i < power; ++i) 
        {
            result *= tempResult;
        }
    } 
    else 
    {
        cout << "Error: Negative powers not supported\n";
    }
    pthread_mutex_unlock(&m1);

    pthread_exit(NULL);
}
void *log_fun(void *arg)
{
	pthread_mutex_lock(&m1);	
        cout<<"Enter the base value : ";
        cin>>base;
        result=log(result)/log(base);
            
        pthread_mutex_unlock(&m1);
        pthread_exit(NULL);
            	
}
void *sin_fun(void *arg)
 {
            //result=sin(num);
            pthread_mutex_lock(&m1);
            double deg,rad,sin,x;
            cout<<"Enter the degrees : ";
            cin>>deg;
            
	    rad=deg * 3.141592653589793 / 180.0;
	    x=rad;
	    sin= x-(x*x*x)/(3*2)+(x*x*x*x*x)/(5*4*3*2)-(x*x*x*x*x*x*x)/(7*6*5*4*3*2);
	    if(deg==0)
            {
            	result=round(sin);
            }
            else if(deg==90)
            {
            	result=round(sin);
            }
            else if(deg==270)
            {
            	result=-1;
            }	
            else if(deg==180)
            {
            	result=round(sin)*-1;
            }
            else
            {
            	result=sin;
            }
             pthread_mutex_unlock(&m1);	  
              pthread_exit(NULL); 
            
        }
void *cos_fun(void *arg)
{
            pthread_mutex_lock(&m1);
            double deg,rad,x;
            cout<<"Enter the degrees : ";
            cin>>deg;
            
	    rad=deg * 3.141592653589793 / 180.0;
	    x=rad;
	    double cos=1-(x*x)/(2)+(x*x*x*x)/(4*3*2)-(x*x*x*x*x*x)/(6*5*4*3*2);
	    if(deg==90)
	    {
	    	result=round(cos)*-1;
	    }
	    else if(deg==180)
	    {
	    	result=round(cos);
	    }
	    else if(deg==270)
	    {
	    	result=-1;
	    }
	    else
	    {
	    	result=cos;
	    }
            pthread_mutex_unlock(&m1);
            pthread_exit(NULL);
}
void *sec_fun(void *arg)
{
		pthread_mutex_lock(&m1);
		double deg,rad,sin,x,cos;
            	cout<<"Enter the degrees : ";
            	cin>>deg;
            	rad=deg * 3.141592653589793 / 180.0;
	    	x=rad;
	    	cos=1-(x*x)/(2)+(x*x*x*x)/(4*3*2)-(x*x*x*x*x*x)/(6*5*4*3*2);
	    	result=1/(cos);
                pthread_mutex_unlock(&m1);
                pthread_exit(NULL);
}
void *tan_fun(void *arg)
{
	    pthread_mutex_lock(&m1);
            double deg,rad,sin,x,cos;
            cout<<"Enter the degrees : ";
            cin>>deg;
            
	    rad=deg * 3.141592653589793 / 180.0;
	    x=rad;
	    sin= x-(x*x*x)/(3*2)+(x*x*x*x*x)/(5*4*3*2)-(x*x*x*x*x*x*x)/(7*6*5*4*3*2);
	    cos=1-(x*x)/(2)+(x*x*x*x)/(4*3*2)-(x*x*x*x*x*x)/(6*5*4*3*2);
	    result=(sin)/(cos);
            pthread_mutex_unlock(&m1);
            pthread_exit(NULL);
}
