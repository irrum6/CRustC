//ch8e
use std::env;

fn count_beer(mut n:u32){
    loop{
        if n<1 {
            println!("No more bottles of beer on the wall, no more bottles of beer.");
            println!(" We've taken them down and passed them around; now we're drunk and passed out!");
            break; 
        }
        println!("{} bottles of beer on the wall, {} bottles of beer.",n,n);
        n=n-1;
        println!("Take one down, pass it around, {} bottles of beer on the wall...",n);
    }
}

fn count_green_bottles(mut n:u32){
    loop{
        println!("{} green bottles standing on the wall,",n);
        println!("{} green bottles standing on the wall,",n);
        println!("And if one green bottle should accidentally fall,");
        n = n-1;
        if n<1 {
            println!("There'll be no green bottles hanging on the wall. ");
            break;
        }
        println!("There'll be {} green bottles hanging on the wall. ",n);
    }
}

fn main(){
    let args: Vec<String> = env::args().collect();

    if args.len() < 2 {
        println!("pass enough parameters to calculate");
        return;
    }

    let n:u32 = args[1].trim().parse().expect("type a number");
    
    if args.len() >2 {       
        if args[2]=="green"{
            count_green_bottles(n);
        }else{
            count_beer(n);
        }
        return ;
    }    
    count_beer(n);    
}
