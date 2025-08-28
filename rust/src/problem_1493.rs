use std::cmp;

pub fn longest_subarray(nums: Vec<i32>) -> i32 {

        let mut g: Vec<i32> = vec![0];
        let mut j = 0;
        for i in 0..nums.len() {
            if nums[i] == 1 {
                g[j]+=1;
            }else{
                j+=1;
                g.push(0);
            }
        }

        if g.len() == 1 {
            return g[0] - 1;
        }

        let mut r = 0;
        for i in 1..g.len() {
            r = cmp::max(g[i]+g[i-1], r);
        }

        return r;
}