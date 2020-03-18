use std::env;

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

fn main() {
    let args: Vec<String> = env::args().collect();
    // println!("len:{}\n", args.len());
    // println!("{:?}", args);

    if args.len() < 3 {
        println!("pass enough parameters to calculate");
        return;
    }

    println!("{}", args[1]);

    let op1: f32 = args[2].trim().parse().expect("type a number");

    let mut op2: f32 = 0.0;
    if args.len() > 3 {
        op2 = args[3].trim().parse().expect("type a number");
    }

    let value: f32 = match args[1].as_ref() {
        "force" | "f" => force(op1, op2),
        "forceN" | "fN" | "fn" => force_libre_newtons(op1, false),
        "forcelb" | "fP" | "fp" => force_libre_newtons(op1, true),
        "energy" | "E" | "e" => energy(op1, op2),
        "energyJ" | "EJ" | "ej" => pound_foot_jouls(op1, false),
        "energyLFT" | "EP" | "ep" => pound_foot_jouls(op1, true),
        "mass" | "M" | "m" => mass(op1, op2),
        "acceleration" | "a" => acceleration(op1, op2),
        "pounds" | "LB" | "lb" | "p" => pound_kg(op1, false),
        "kilos" | "KG" | "kg" => pound_kg(op1, true),
        "meters" | "mt" | "MT" => foot_meter(op1, false),
        "foots" | "ft" | "FT" => foot_meter(op1, true),
        _ => 0.0, //defaultness
    };

    println!("{} is {}", args[1].to_string(), value);
}
