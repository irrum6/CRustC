#[cfg(test)]
pub mod tests {
    use crate::sort::sorter as sorters;
    #[test]
    fn bubble_sort_test(){
        // 0   1   2 3 4 5   6 7   8  9  10  11     12 13  14 15 
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
    #[test]
    fn dummy_test(){
        assert_eq!(sorters::dummy(),4);
    }
}