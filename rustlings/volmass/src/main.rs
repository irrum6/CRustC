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

use std::env;
fn main() {
    let args: Vec<String> = env::args().collect();

    if args.len() < 3 {
        println!("pass enough parameters to calculate");
        return; 
    }

    let param1:f64 = args[1].trim().parse().expect("number");
    let param2:f64 = args[2].trim().parse().expect("number");

    let c = Cylinder{radius:param1,height:param2};

    print_volume(&c);

    if args.len() > 3 {
        let dens:f64 = args[3].trim().parse().expect("number");
        print_mass(c, dens);
    }

}
