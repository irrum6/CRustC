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

// Binary_GCD_algorithm
fn bgcd(mut a:u32, mut b :u32)->u32{
    return 0;
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

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        println!("pass enough parameters to calculate");
        return;
    }

    if args[1] == "test"{
        let failure:String = String::from("The test has failed");
        let sucess:String = String::from("The test run sucessfully");
        // println!("{}",test_legcd()?sucess:failure);
        if test_legcd() {println!("{}",sucess);} else {println!("{}",failure);}
    }else{
        let fst:u32 = args[1].trim().parse().expect("type a number");
        let snd:u32 = args[2].trim().parse().expect("type a number");
        println!("Greatest common divisor of {} and {} divisor is {}",fst,snd,legcd(fst,snd));
    }    
}
