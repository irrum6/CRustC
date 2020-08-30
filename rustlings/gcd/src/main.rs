use std::env;

//euclidean gcd
fn legcd(mut a:u32,mut b:u32)->u32{
    while a != b {
        if a > b{
            a = a - b ;
        }            
        else{
            b = b - a ;
        }    
    }        
    return a;
}

fn is_even(a:u32)->bool{
    if a%2==0 {
        return true;
    }
    return false;
}
// Binary_GCD_algorithm
fn bgcd(a:u32, b :u32)->u32{
    // https://iq.opengenus.org/binary-gcd-algorithm/ 
    // AKA Stein’s algorithm
    if a == b { return a }
    if a == 0 { return b }
    if b == 0 { return a } 

    if is_even(a) && is_even(b){
        return bgcd(a >> 1, b >> 1) << 1;
    }
    else if is_even(a){
        return bgcd(a >> 1, b);
    }
    else if is_even(b){
        return bgcd(a, b >> 1);
    }    
    else if a >= b{
        return bgcd((a-b) >> 1, b);
    }
    else{
        return bgcd(a, (b-a) >> 1);
    }
}
// iterative binary gcd
fn bgcd_it(mut a:u32,mut b:u32)->u32{
    use std::cmp::min;
    use std::mem::swap;
    if a == 0 { return b }
    if b == 0 { return a }

    let i:u32= a.trailing_zeros();
    let j:u32= b.trailing_zeros();
    let k:u32= min(i,j);

    a >>= i;b >>= j;

    // both odd
    loop{
        if a > b {
            swap(&mut a, &mut b);
        }
        b= b - a;
        if b == 0 {
            break;
        }
        b >>= b.trailing_zeros();
    }
    return a<<k;
}

fn test_legcd()->bool{
    let primes:[u32;10] =  [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
    for p in primes.iter(){
        for q in primes.iter(){
            if p==q{
                continue;
            }
            let n1:u32 = p * q;
            let n2:u32 = q * q;
            // println!("{},{},{},{},{}",p,q,n1,n2,legcd(n1,n2));
            if legcd(n1,n2) != *q {
                return false;
            }
        }
    }
    return true;
}

fn test_bgcd(m:u32)->bool{
    let primes:[u32;10] =  [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
    for p in primes.iter(){
        for q in primes.iter(){
            if p==q{
                continue;
            }
            let n1 = p * q;
            let n2 = q * q;
            let mut result = bgcd(n1,n2);
            if m==1 {result = bgcd_it(n1,n2) }
            if result != *q {
                return false;
            }
        }
    }
   return true; 
}
fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("pass enough parameters to calculate");
        return;
    }    
    let failure:String = String::from("The test has failed");
    let sucess:String = String::from("The test run sucessfully");
    if args[1] == "test"{        
        // println!("{}",test_legcd()?sucess:failure);
        if test_legcd() {println!("{}",sucess);} else {println!("{}",failure);}
    }
    if args[1] == "testb"{
        if test_bgcd(0) {println!("{}",sucess);} else {println!("{}",failure);}
    }
    if args[1] == "testbit"{
        if test_bgcd(0) {println!("{}",sucess);} else {println!("{}",failure);}
    }
    
    if args.len() > 3 {
        if args[1]=="bin" {
            let fst:u32 = args[2].trim().parse().expect("type a number");
            let snd:u32 = args[3].trim().parse().expect("type a number");
            println!("Greatest common divisor of {} and {} divisor is {}",fst,snd,bgcd(fst,snd));
        }        
    }
    // println!("{}",4>>1);    
}
