fn calculate_next(line:String)->String{
    let mut returner = String::new();
    let mut chars: Vec<char> = line.chars().rev().collect();
    let mut counter:u32 = 0;
    let mut last_char:char = '+';

    loop{
        let c = chars.pop().unwrap();
        
        if c != last_char && last_char != '+' {            
            let strong = format!("{}{}", counter,last_char);
            returner.push_str(&strong);
            counter = 0;
        }
        counter += 1;
        if chars.len() == 0 {
            let strong = format!("{}{}", counter,c);
            returner.push_str(&strong);
            break;
        }
        last_char = c ;
    }
    return returner;
}

fn main() {
    let mut strange = String::from("1");
    for _i in 1..=40 {
        println!("Hello, We are legion our numbers are {} !",strange.clone());
        strange = calculate_next(strange);
    }
}
