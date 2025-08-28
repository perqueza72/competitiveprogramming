mod problem_1493;

fn main() {
    let r = problem_1493::longest_subarray(vec![0,1,1,1,0,1,1,0,1]);
    print!("Result: {}\n", r);

    let r = problem_1493::longest_subarray(vec![1,1,1]);
    print!("Result: {}\n", r);

    let r = problem_1493::longest_subarray(vec![1,1,0,1]);
    print!("Result: {}\n", r);

    let r = problem_1493::longest_subarray(vec![0]);
    print!("Result: {}\n", r);

}