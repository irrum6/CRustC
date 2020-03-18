use std::env;

fn test_op(a:i32,b:i32,c:i32,op:char){
    let value: bool = match op {
        '+' if a+b==c =>true ,
        '*' if a*b==c =>true,
        '/' if a/b==c => true,
        '-' if a-b==c =>true,
        _ => false, //defaultness
    };
    if value {
        println!("{} {} {} = {}",a,op,b,c);
    }
}

fn deduce_relation(a:i32,b:i32,c:i32){
    //multiplication
    test_op(a,b,c,'*');
    test_op(a,c,b,'*');
    test_op(b,c,a,'*');
    //add
    test_op(a,b,c,'+');
    test_op(a,c,b,'+');
    test_op(b,c,a,'+');
    //division
    test_op(c,b,a,'/');
    test_op(b,c,a,'/');
    test_op(a,b,c,'/');
    //substract
    test_op(a,b,c,'-');
    test_op(c,a,b,'-');
    test_op(b,a,c,'-');
}

fn main() {
    let args: Vec<String> = env::args().collect();
    
    if args.len() < 4 {
        println!("pass enough parameters to calculate");
        return;
    }

    let a:i32= args[1].trim().parse().expect("type a number");
    let b:i32= args[2].trim().parse().expect("type a number");
    let c:i32= args[3].trim().parse().expect("type a number");

    deduce_relation(a,b,c);
}