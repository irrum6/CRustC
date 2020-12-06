use std::env;
mod sort;
use sort::sorter as sorters;
mod tests;

fn main() {
    let args: Vec<String> = env::args().collect();
    let mut numbers:Vec<u64> = Vec::new();

    for _i in 1 .. args.len(){
        let num:u64 = args[_i].trim().parse().expect("type a number");
        numbers.push(num);
    }    
    
    sorters::cocktail_shaker_sort(&mut numbers);
    //print sorted 
    for n in numbers {
        print!("{}:",n);
    }
    println!("Hell Yeah!");
}
