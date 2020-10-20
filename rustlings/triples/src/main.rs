// challenge 71 easy
use std::env;

fn triples(n:u32){
     //a+b+c <=total
    //if c=0 a<=b <total/2
    let max = n / 2 ;
    for a in 1..max{
        for b in 1..max {
            let c = n - a - b;
            if a*a + b*b == c*c {
                println!("Pithagoran triple a={} b={} c={}",a,b,c);
            }
        }
    }
}

fn triples2(n:u32){
    let max = n / 2 ;
    for a in 1..max / 2 +1{
        for b in 1..max {
            let c = n - a - b;
            if a*a + b*b == c*c {
                println!("Pithagoran triple a={} b={} c={}",a,b,c);
            }
        }
    }
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("pass enough parameters to calculate");
        return;
    }

    let total:u32 = args[1].trim().parse().expect("type a number");
    println!("---triples---");
    triples(total);
    println!("---triples2---");
    triples2(total);
    println!("---Have a nice day. :)---");
}
