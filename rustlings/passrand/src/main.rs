use std::time::{SystemTime, UNIX_EPOCH};
use std::env;
use std::convert::TryInto;
use std::convert::TryFrom;

fn xor_shift_rng(w:&mut u32,x:&mut u32,y:&mut u32,z:&mut u32){
    let tmp:u32 = *x^(*x<<15);

    *x = *y;
    *y = *z;
    *z = *w;
    
    *w = (*w^(*w>>21))^(tmp^(tmp>>4));
}

fn seed_with_nanosecs(x:&mut u32){
    *x =  SystemTime::now()
    .duration_since(UNIX_EPOCH)
    .unwrap()
    .subsec_nanos();
}

fn main() {
    let args: Vec<String> = env::args().collect();
    
    if args.len() < 2 {
        println!("pass enough parameters to calculate");
        return;
    }

    let mut w:u32 = 0;
    let mut x:u32 = 0;
    let mut y:u32 = 0;
    let mut z:u32 = 0;

    seed_with_nanosecs(&mut w);
    seed_with_nanosecs(&mut x);
    seed_with_nanosecs(&mut y);
    seed_with_nanosecs(&mut z);

    let amount:u32= args[1].trim().parse().expect("type a number");

    let mut length: u32 = 12; //default 12 character length password

    if args.len() > 2 {
        length = args[2].trim().parse().expect("type a number");
    }

    let charski = vec!["ა","ბ","გ","დ","ე","ვ","ზ","თ","ი","კ",
    "ლ","მ","ნ","ო","პ","ჟ","რ","ს","ტ","უ","ფ","ქ","ღ","ყ","შ",
    "ჩ","ც","ძ","წ","ჭ","ხ","ჯ","ჰ","ა","ა","ე","ე","ი","ო","უ"];
    let l:u32= charski.len().try_into().unwrap();

    for _i in 0..amount{
        for _j in 0..length{
            xor_shift_rng(&mut w, &mut x, &mut y, &mut z);
            let index:u32 = w % l;
            let n_us = usize::try_from(index).unwrap();
            print!("{}", charski[n_us]);
        }
        print!("\n");
    }

}