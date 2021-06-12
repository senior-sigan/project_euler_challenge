//
// Project Euler: Problem 1: Multiples of 3 and 5
// If we list all the natural numbers below 10 that are multiples of 3 or 5, we
// get 3, 5, 6 and 9. The sum of these multiples is 23.
//
// Find the sum of all the multiples of 3 or 5 below the provided parameter
// value number.
//

pub fn multiples_of_3_and_5(number: i32) -> i32 {
    let mut sum = 0;
    for i in 0..number {
        if i % 3 == 0 || i % 5 == 0 {
            sum += i
        }
    }
    return sum;
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_all() {
        assert_eq!(multiples_of_3_and_5(10), 23);
        assert_eq!(multiples_of_3_and_5(49), 543);
        assert_eq!(multiples_of_3_and_5(1000), 233168);
        assert_eq!(multiples_of_3_and_5(8456), 16687353);
        assert_eq!(multiples_of_3_and_5(19564), 89301183);
    }
}