// ch8i
use std::env;

fn sub_thousand (t:u32){
    if t> 99 {
        print!("{} hundred ",digits(t/100));
        sub_hundred(t%100);
        return;
    }
    sub_hundred(t%100)
}

fn sub_hundred (h:u32){
    if  h<10 {
        print!(" {} ",digits(h));
        return;
    }
    if h<20 {
        print!(" {} ",teens(h));
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
        11 => "eleven",
        10 => "ten",
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
        0 => "",
        1 => "thousand",
        2 => "million",
        3 => "billion",
        _ => ""
    };
    return String::from(value);
}
// reverse
fn kilo_r(s:String)->u32{
    let val:u32 = match s.as_ref(){
        "thousand" => 1000,
        "million" => 1000000,
        "billion" => 1000000000,
        _ => 1
    };
    return val;
}
fn sub_hundred_r(s:String) ->u32{
    let value :u32 = match s.as_ref(){
        "ninety" =>90,
        "eighty" =>80,
        "seventy" =>70,
        "sixty" => 60,
        "fifty"=> 50,
        "fourty" =>40,
        "thirty" => 30,
        "twenty" => 20,
        "nineteen" =>19,
        "eighteen" =>18,
        "seventeen" =>17,
        "sixteen" => 16,
        "fifteen"=> 15,
        "fourteen" =>14,
        "thirteen" => 13,
        "twelve" => 12,
        "eleven" => 11,
        "ten" => 10,
        "nine" => 9,
        "eight" => 8,
        "seven" => 7,
        "six" => 6,
        "five" => 5,
        "four" => 4,
        "three" => 3,
        "two" => 2,
        "one" => 1,
        "zero" => 0,
        _ => 0
    };
    return value;
}

fn sub_thousand_r(s:Vec<String>)->u32{
    let mut val:u32 = 0;
    if s.len()<1 {
        return 0;
    }
    for ss in s {
        if ss == "hundred" {
            val *=100;
            continue;
        }
        val += sub_hundred_r(ss);
    }
    return val;
}

fn main() {
    let args: Vec<String> = env::args().collect();
    
    if args.len() < 2 {
        println!("pass enough parameters to calculate");
        return;
    }

    let mut count:u32 = 0;
    if args[1]=="read" {
        let mut number:u32 = 0;

        let mut oargs:Vec<String>= Vec::new();

        for arg in args{
            count += 1;
            
            if count < 3 {
                continue;
            }
            oargs.push(String::clone(&arg));            
            let power = kilo_r(String::clone(&arg));
            if power > 1 {
                oargs.pop();//remove last
                number += sub_thousand_r(Vec::clone(&oargs)) * power;
                println!("number is {}",number);
                oargs.clear();
            }
                       
        }

        number += sub_thousand_r(Vec::clone(&oargs));
        println!("number is {}",number);
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
