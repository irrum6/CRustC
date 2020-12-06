pub mod sorter {
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
    pub fn dummy()->u32{
        return 4;
    }
}