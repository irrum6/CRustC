//  days between days
fn days_between(date1: String, date2: String) -> i32 {
    let date1 = epoch_days(date1);
    let date2 = epoch_days(date2);

    (date1 - date2).abs()
}
//from_1970_01_01
fn epoch_days(date: String) -> i32 {
    let days_by_month = [0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334];
    let date = date.split('-').map(|s| s.parse().unwrap()).collect::<Vec<i32>>();
    //days by previous month plus this months passed days
    let mut days = days_by_month[(date[1]- 1) as usize ] + date[2] - 1 ;
    //leap rules
    if date[0] % 4 == 0 && date[0] != 2100 && date[1] > 2 {
        days += 1;
    }
    days += 36525 * (date[0] - 1970) / 100;
    if (date[0] - 1)%4==0 {
        days += 1;
    }
    return days;
}

#[cfg(test)]
mod tests {
    use crate::days_between;
    #[test]
    fn test() {
        let date1 = String::from("2020-06-01");
        let date2 = String::from("2020-06-01");
        let x = days_between(date1, date2);   
        assert_eq!(x,0);
        let date1 = String::from("2020-06-01");
        let date2 = String::from("2020-06-02");        
        let x = days_between(date1, date2);
        assert_eq!(x,1);
        let date1 = String::from("2020-06-01");
        let date2 = String::from("2020-07-01");        
        let x = days_between(date1, date2);
        assert_eq!(x,30);
        let date1 = String::from("1970-06-01");
        let date2 = String::from("1970-07-01");        
        let x = days_between(date1, date2);
        assert_eq!(x,30);        
    }
    #[test]
    fn leap_to_nonleap () {
        let date1 = String::from("2016-12-31");
        let date2 = String::from("2017-01-02");        
        let x = days_between(date1, date2);
        assert_eq!(x,2);
        let date1 = String::from("2020-12-01");
        let date2 = String::from("2021-01-02");        
        let x = days_between(date1, date2);
        assert_eq!(x,32);
    }
    #[test]
    fn nonleap_to_leap () {
        let date1 = String::from("2015-12-31");
        let date2 = String::from("2016-01-01");        
        let x = days_between(date1, date2);
        assert_eq!(x,1);
        let date1 = String::from("2019-12-01");
        let date2 = String::from("2020-01-01");        
        let x = days_between(date1, date2);
        assert_eq!(x,31);
        let date1 = String::from("2015-01-01");
        let date2 = String::from("2018-01-01");        
        let x = days_between(date1, date2);
        assert_eq!(x,1096);
    }
}

fn main() {
    let date1 = String::from("2020-07-01");
    let date2 = String::from("2020-08-02");  
    let dayz = days_between(date1.clone(), date2.clone());
    assert_eq!(dayz,32);
    println!("There are {} days between {} and {}.",dayz,date1,date2);
    let date1 = String::from("2020-12-31");
    let date2 = String::from("2021-01-01");
    println!("days from 1970-01-01 to {} is :{}" ,date1.clone() ,epoch_days(date1));
    println!("days from 1970-01-01 to {} is :{}" ,date2.clone() ,epoch_days(date2));
}