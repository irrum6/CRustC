use std::io;

// fn fibonaci_recurse(n:u32)->u32{
//     if n<3 {return 1;}
//     return fibonaci_recurse(n-1)+fibonaci_recurse(n-2);
// }

fn fibonaci_iter(n:u32)->u32{
    if n<3 {return 1;}
    let mut a:u32=1;
    let mut b:u32=1;
    for _i in 1..n {
        a = a + b;
        b = a - b;
    }
    return a;
}

fn main(){
    let mut user_input=String::new();

    println!("type a number");

    io::stdin().read_line(&mut user_input).expect("Failed to read");

    let number:u32= user_input.trim().parse().expect("type a number");

    println!("the value of {}th fibonaci number is:{}", number,fibonaci_iter(number));
}