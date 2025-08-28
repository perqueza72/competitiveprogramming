pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {

        let mut r = 0;
        let mut a_r = 0;
        for i in 0..dimensions.len(){
            let diagonal = dimensions[i][0]*dimensions[i][0] + dimensions[i][1]*dimensions[i][1];


            if diagonal == r {
                let area = dimensions[i][0]*dimensions[i][1];
                if area > a_r {
                    r = diagonal;
                    a_r = dimensions[i][0]*dimensions[i][1];    
                }
            }
            else if diagonal > r {
                r = diagonal;
                a_r = dimensions[i][0]*dimensions[i][1];
            }
        }

        return a_r;
    }

