use std::env;

/*
    Precedence: (lower - higher)
    - left 2
    + left 3
    / left 4
    * left 5
*/

fn ops(a: f32, b: f32, ch: char) -> f32 {
    let value: f32 = match ch {
        '+' => a + b,
        '-' => a - b,
        '*' => a * b,
        '/' => a / b,
        _ => 0.0,
    };

    return value;
}

fn is_op(c:char)->bool{
    let value: bool = match c {
        '+' => true,
        '-' => true,
        '*' => true,
        '/' => true,
        _ =>false
    };

    return value;
}

fn is_digit(c:char)->bool{
    let value: bool = match c {
        '0' => true,
        '1' => true,
        '2' => true,
        '3' => true,
        '4' => true,
        '5' => true,
        '6' => true,
        '7' => true,
        '8' => true,
        '9' => true,
        _ =>false
    };

    return value;
}

fn eval(exp:&String)->f32{
    let mut value = 0.0;
    let empty="".to_string();
    // let mut tokens=vec![];
    let mut tokens=vec![1,23];
    //vec (string, len:s.len)

    let mut tok:String=empty.clone();

    tokens.pop();

    for c in exp.chars(){
        if is_digit(c){
            tok.push(c);
            continue;
        }
        if is_op(c){
            let mut tok1 = tok.clone();
            tok="".to_string();
            // tokens.push(& tok1);
        }
    }

    return value;
} 

fn parenthesis_matched(s: &String) -> bool {
    let mut opens: u32 = 0;
    let mut closed: u32 = 0;

    for c in s.chars() {
        if c == '(' {
            opens += 1;
        }
        if c == ')' {
            closed += 1;
        }
    }
    return opens == closed;
}

fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("pass enough parameters to calculate");
        return; 
    }

    let mut bmatch = "";
    if !parenthesis_matched(&args[1]) {
        bmatch = "didn\'t";
    }
    println!("parenthesis {} match", bmatch);
    
}
