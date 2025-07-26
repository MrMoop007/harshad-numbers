#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

long long int sum_of_digits(long long int n){
    int sum = 0;
    while(n > 0){
        sum += n%10;
        n /= 10;
    }
    return sum;
}

bool harshad_number(long long int n){
    return n%sum_of_digits(n) == 0;
}

bool is_prime(long long int n){
    if(n == 2){
        return true;
    }
    int i;
    for(i = 2; i < (int)pow(n, 0.5) + 1; i++){
        if(n%i == 0){
            return false;
        }
    }
    return true;
}

bool strong_harshad_number(long long int n){
    bool result = harshad_number(n) && is_prime(n/sum_of_digits(n));
    return result;
}

bool right_truncatable_harshad_number(long long int n){
    if(harshad_number(n)){
        return harshad_number(n/10);
    }
    else{return false;}
}

bool strong_right_truncatable_harshad_number(long long int n){
    if(is_prime(n)&&n/10>=10){
        n /= 10;
        return strong_harshad_number(n) && right_truncatable_harshad_number(n);
    }
    else{return false;}
}

int main(){
    char strbound[64];
    printf("Enter the bound for the harshad numbers: ");
    scanf("%s", strbound);
    long long int bound = strtol(strbound, NULL, 10);
    printf("\n");
    long long int i;
    long long int total = 0;
    int percent = 0;
    for(i = 1; i<bound; i++){
        if(strong_right_truncatable_harshad_number(i)){
            total += i;
        }
        //if(i%(bound/100) == 0){
        //    printf("%d percent finished\n");
        //    percent ++;
        //}
    }
    printf("the sum of the strong, right truncatable Harshad primes less than %d is %d", bound, total);
    return 0;
}