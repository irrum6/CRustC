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

fn test_bgcd()->bool{
    let primes:[u32;10] =  [2, 3, 5, 7, 11, 13, 17, 19, 23, 29];
    for p in primes.iter(){
        for q in primes.iter(){
            if p==q{
                continue;
            }
            let n1:u32 = p * q;
            let n2:u32 = q * q;
            // println!("{},{},{},{},{}",p,q,n1,n2,legcd(n1,n2));
            if bgcd(n1,n2) != *q {
                return false;
            }
        }
    }
   return true; 
}
fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        println!("pass enough parameters to calculate");
        return;
    }
    let failure:String = String::from("The test has failed");
        let sucess:String = String::from("The test run sucessfully");
    if args[1] == "test"{        
        // println!("{}",test_legcd()?sucess:failure);
        if test_legcd() {println!("{}",sucess);} else {println!("{}",failure);}
    }else if args[1] == "testb"{
        if test_bgcd() {println!("{}",sucess);} else {println!("{}",failure);}
    }
    else{
        let fst:u32 = args[1].trim().parse().expect("type a number");
        let snd:u32 = args[2].trim().parse().expect("type a number");
        println!("Greatest common divisor of {} and {} divisor is {}",fst,snd,legcd(fst,snd));
    }
    // println!("{}",4>>1);    
}
