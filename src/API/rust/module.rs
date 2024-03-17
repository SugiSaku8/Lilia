use std::fs;
use std::io::{self, BufRead};
use std::path::Path;

fn get_device_info(device_name: &str) -> io::Result<String> {
    let path = Path::new("info.txt");
    let file = fs::File::open(&path)?;
    let reader = io::BufReader::new(file);

    for line in reader.lines() {
        let line = line?;
        if line.starts_with(device_name) && line.contains(':') {
            let info = line.split(':').collect::<Vec<&str>>()[1].trim_matches('"');
            return Ok(info.to_string());
        }
    }
    Ok("Device not found".to_string())
}