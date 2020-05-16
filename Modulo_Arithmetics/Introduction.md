###  10^9 + 7   
- Prime number. Sometimes the result is so high that it is not possible to store in int, and it will overflow the integer range.   
- So, in competetive programming we take modulo with this no.    
- Its large enough to capture a lot of values
- It is prime so will give more unique answers, more spacing as modulo will be different with different numbers   

- Max positive number that can be stored in long long   -   10^64 - 1   

  Suppose, we want to multiply 10^32 * 10^40 , result will overflow range. So, we would take modulo.    

## Modulo Properties  
1. (a+b)%c = (a%c + b%c)%c   
2. (a*b)%c = (a%c * b%c)%c  - Since the multiplication can exceed int range , its better to store in long long   
3. (a-b)%c = (a%c - b%c)%c    
4. ~~(a/b)%c = (a%c / b%c)%c~~   - For division we need to take modulo inverse    

### More...   

- Range of modulo 0 <= m <= m-1     
- If modulo is negative    
    -5%3  =   -2    
    do, (no%m+m)%m     
    (-5%3 + 3)%3  =  1     


