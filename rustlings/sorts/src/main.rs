pub mod sorters {
    pub fn bubble_sort(a:&mut Vec<u64>){
        loop {
            let mut swapped = 0;
            for _i in 1 .. a.len() {
                if a[_i-1] > a[_i]{
                    //inline swap
                    a[_i-1] =  a[_i-1] + a[_i];
                    a[_i] = a[_i-1] - a[_i];
                    a[_i-1] =  a[_i-1] -  a[_i];
                    swapped = 1;
                }
            }
            if swapped == 0 {break;}
        }
    }
    // https://en.wikipedia.org/wiki/Bubble_sort#Optimizing_bubble_sort
    pub fn bsorto(a:&mut Vec<u64>){
        let mut n:usize = a.len();
        loop {
            let mut swapped = 0;
            for _i in 1.. n{
                if a[_i-1] > a[_i]{
                    //inline swap
                    a[_i-1] =  a[_i-1] + a[_i];
                    a[_i] = a[_i-1] - a[_i];
                    a[_i-1] =  a[_i-1] -  a[_i];
                    swapped = 1;
                }
            }
            n = n - 1;
            if swapped == 0 {break;} 
        }
        // println!("gela var gelava");
    }
    
    pub fn bubble_sort2 (a:&mut Vec<u64>){
        let mut n:usize = a.len();
        loop {
            let mut newn = 0;
            for _i in 1.. n {
                if a[_i-1] > a[_i]{
                    //inline swap
                    a[_i-1] =  a[_i-1] + a[_i];
                    a[_i] = a[_i-1] - a[_i];
                    a[_i-1] =  a[_i-1] -  a[_i];
                    newn = _i;
                }
            }
            n  = newn;
            if n < 1 {break;} 
        }
    }
    pub fn cocktail_shaker_sort (a:&mut Vec<u64>){
        let n:usize = a.len();
        loop {
            let mut swapped = 0;
            for _i in 0..=n-2 {
                if a[_i] > a[_i+1]{
                    //inline swap
                    a[_i] =  a[_i] + a[_i+1];
                    a[_i+1] = a[_i] - a[_i+1];
                    a[_i] =  a[_i] -  a[_i+1];
                    swapped = 1;
                }
            }
            if swapped == 0 {break;}
            swapped = 0;
            for _i in (0..=n-2).rev() {//thanks stackoverflow
                if a[_i] > a[_i+1]{
                    //inline swap
                    a[_i] =  a[_i] + a[_i+1];
                    a[_i+1] = a[_i] - a[_i+1];
                    a[_i] =  a[_i] -  a[_i+1];
                    swapped = 1;
                }
            }
            if swapped == 0 {break;}
        }
    }
}
#[cfg(test)]
mod tests {    
    use super::sorters as sorters;
    #[test]
    fn bubble_sort_test(){
        // 0 1   2 3 4 5   6 7   8  9  10  11     12 13  14 15 
        // 21 13 5 1 3 34 89 55 144 11 2342 12341 45 32 235 12
        let mut numbers:Vec<u64> = vec![21 ,13 ,5 ,1 ,3 ,34 ,89 ,55 ,144 ,11 ,2342 ,12341 ,45 ,32 ,235 ,12];
        sorters::bubble_sort(&mut numbers);
        assert_eq!(numbers[15],12341);
    }
    #[test]
    fn  bsorto_test(){
        let mut numbers:Vec<u64> = vec![21 ,13 ,5 ,1 ,3 ,34 ,89 ,55 ,144 ,11 ,2342 ,12341 ,45 ,32 ,235 ,12];
        sorters::bsorto(&mut numbers);
        assert_eq!(numbers[3],11);
    }
    #[test]
    fn  bubble_sort2_test(){
        let mut numbers:Vec<u64> = vec![21 ,13 ,5 ,1 ,3 ,34 ,89 ,55 ,144 ,11 ,2342 ,12341 ,45 ,32 ,235 ,12];
        sorters::bubble_sort2(&mut numbers);
        assert_eq!(numbers[3],11);
    }
    #[test]
    fn cocktail_shaker_test (){
        let mut numbers:Vec<u64> = vec![21 ,13 ,5 ,1 ,3 ,34 ,89 ,55 ,144 ,11 ,2342 ,12341 ,45 ,32 ,235 ,12];
        sorters::bubble_sort2(&mut numbers);
        assert_eq!(numbers[6],21);
    }
}

use std::env;
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
