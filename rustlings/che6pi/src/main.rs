// adapted for rust from
// https://crypto.stanford.edu/pbc/notes/pi/code.html
fn pi_100 (){
    //1401 integers with value of 2000
    //seems repeat must match array size
    let mut r:[i32;1401] = [2000;1401];
    let mut i:i32;
    let mut k:i32 = 1400;
    let mut b:i32;
    let mut d:i32;
    let mut c:i32 = 0;

    r[1400]=0;

    let mut breaker = 0;
    loop{
        breaker += 1;
        if k <= 0 {break};
        d = 0;
        i = k;
        loop {
            d += r[i as usize] * 10000;
            b = 2 * i - 1;

            r[i as usize] = d % b;
            d /= b;
            i -= 1;
            if i == 0 {break};
            d *= i;
        }
        print!("{}", c + d / 10000);
        c = d % 10000;
        k -=14;

        //every eight times print line and reset
        if breaker ==  8 {            
            println!(" >>");
            breaker = 0;
        }
    }
}

fn main() {
    pi_100();
}