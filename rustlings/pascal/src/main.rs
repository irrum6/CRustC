use std::env;

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        println!("== ERROR :  Not Enough parameters were passed ==");
        return;
    }

    let number1:usize = args[1].trim().parse().expect("type a number");
    let number2:usize = args[2].trim().parse().expect("type a number");

    if number2 > number1 {
        println!("== ERROR : Wrong order. ==");
        return;
    }
    let mut pre:[u32;200]=[0;200];
    let mut tri:[u32;200]=[0;200];
    
    if number1 > 0 {
        pre[0] = 1;
        tri[0] = 1;
    }
    if  number1 > 1 {
        pre[1] = 1;
        tri[1] = 1;
    }

    for _i in 2 .. number1{
        tri[0] = 1;
        for _j in 1..number1 {
            tri[_j] = pre[_j-1]+pre[_j];
        }
        for _j in 0..number1-1{
            pre[_j] = tri[_j];
        }
    }

    if number2 > 0 && number2 < number1 {
        println!("pascal number at row {} column {} is {}",number1,number2,tri[number2-1]);
    }
    if number2 < 1 || number2 ==number1{
        println!("pascal number at row {} column {} is {}",number1,number2,1);
    }
   

    if args.len() > 3 && args[3] =="print" {
        for _k in 0 ..number1{
            print!("{} ", tri[_k]);
        }
    }
}

// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
// 1 6 15 20 15 6 1
// 1 7 21 35 35 21 7 1
// 1 8 28 56 70  56  28 8 1
// 1 9  36 84 126 126 84  36 9 1
// 1 10 45 120 210 252 210 120 45 10 1

