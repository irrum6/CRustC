trait HasVolume {
    fn volume (&self) ->f64;
}
trait HasMass {
    fn mass (&self,density:f64) ->f64;
}

struct Cylinder{
    radius:f64,
    height:f64
}

impl HasVolume for Cylinder{
    fn volume(&self)->f64{
        return self.radius*self.radius * self.height * std::f64::consts::PI;
    }
}
impl HasMass for Cylinder {
    fn mass(&self, density:f64) ->f64{
        return self.volume() * density;
    }
}

struct Cone {
    radius:f64,
    height:f64
}

impl HasVolume for Cone {
    fn volume(&self)->f64{
        let squared = self.radius *  self.radius ;
        return (std::f64::consts::PI * squared * self.height ) / 3.0;
    }
}
struct Sphere {
    radius:f64
}

impl HasVolume for Sphere {
    fn volume(&self)->f64{
        let cubed = self.radius *  self.radius *  self.radius;
        return (4.0 * std::f64::consts::PI * cubed ) / 3.0;
    }
}

fn print_volume<T: HasVolume>(shape: &T) {
    println!("This shape has an volume of {}", shape.volume());
}

fn print_mass<T: HasMass>(shape: T,density:f64) {
    println!("This shape has an mass of {}", shape.mass(density));
}

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

fn force_libre_newtons(force: f32, reverse: bool) -> f32 {
    //newton to libre force
    if reverse {
        return (force / 9.81) / 0.453;
    }
    //libre force to newton
    return force * 0.453 * 9.81;
}

fn pound_foot_jouls(energy: f32, reverse: bool) -> f32 {
    //joul to libre foot
    if reverse {
        return ((energy / 9.81) / 0.3048) / 0.453;
    }
    //librefoot to jouls
    return energy * 0.3048 * 0.453 * 9.81;
}

fn force(mass: f32, acceleration: f32) -> f32 {
    return mass * acceleration;
}
fn energy(force: f32, meters: f32) -> f32 {
    return force * meters;
}

fn mass(force: f32, acceleration: f32) -> f32 {
    return force / acceleration;
}

fn acceleration(force: f32, mass: f32) -> f32 {
    return force / mass;
}

fn pound_kg(mass: f32, reverse: bool) -> f32 {
    if reverse {
        return mass / 0.453;
    }
    return mass * 0.453;
}

fn foot_meter(count: f32, reverse: bool) -> f32 {
    if reverse {
        return count / 0.3048;
    }
    return count * 0.3048;
}
//------------------------------------------
//beercount
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

//------------------------------------------
//
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
