// ch8i
use std::env;

fn sub_thousand (t:u32){
    if t> 99 {
        print!("{} hundred",digits(t/100));
        sub_hundred(t%100);
        return;
    }
    sub_hundred(t%100)
}

fn sub_hundred (h:u32){
    if  h<10 {
        print!("{}",digits(h));
        return;
    }
    if h<20 {
        print!("{}",teens(h));
        return;
    }    
    let dig = digits(h%10);
    let dec = match h/10{
        9 => "ninety",
        8 => "eighty",
        7 => "seventy",
        6 => "sixty",
        5 => "fifty",
        4 => "fourty",
        3 => "thirty",
        2 => "twenty",
        _ => ""
    };
    print!("{}{}",dec,dig);
    return;
}
fn teens (t:u32)->String {
    let value = match t{
        19 => "nineteen",
        18=> "eighteen",
        17 => "seventeen",
        16 => "sixteen",
        15 => "fifteen",
        14 => "fourteen",
        13 => "thirteen",
        12 => "twelve",
        11=> "eleven",
        _ => ""
    };
    return String::from(value);
}
fn digits (d:u32)->String{
    let value = match d{
        9 => "nine",
        8=> "eight",
        7 => "seven",
        6 => "six",
        5 => "five",
        4 => "four",
        3 => "three",
        2 => "two",
        1 => "one",
        0 =>"zero",
        _ => ""
    };
    return String::from(value);
}

fn kilo (t:u32) -> String{
    let value = match t {
        1 => "thousand",
        2 => "million",
        3 => "billion",
        _ => ""
    };
    return String::from(value);
}

fn main() {
    let args: Vec<String> = env::args().collect();
    
    if args.len() < 2 {
        println!("pass enough parameters to calculate");
        return;
    }

    let mut number:u32 = args[1].trim().parse().expect("type a number");

    let mut thousands:Vec<u32> = Vec::new();

    let mut power :u32 = 0;

    println!("number is {}",number);
    
    loop {
        if number <1000 {
            thousands.push(number);
            break;
        }
        thousands.push(number % 1000);
        number = number / 1000;
        power +=1;
    }
    
    loop{
        if thousands.len() < 1 {
            break;
        }
        let t:u32 = thousands.pop().unwrap();
        sub_thousand(t);
        print!(" {} ",kilo(power));
        if power > 0 {
            power-= 1;
        }
    }
    return;
}
