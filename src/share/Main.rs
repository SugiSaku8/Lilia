use clap::{App, Arg, crate_version};
use std::fs::File;
use std::io::{self, Read};
use std::path::Path;
use std::process;

fn main() {
    let matches = App::new("lilia")
        .version(crate_version!())
        .arg(
            Arg::with_name("about")
                .help("About this program")
                .short("a")
                .long("about"),
        )
        .arg(
            Arg::with_name("test")
                .help("Run tests")
                .short("t")
                .long("test"),
        )
        .arg(
            Arg::with_name("help")
                .help("Display help information")
                .short("h")
                .long("help"),
        )
        .get_matches();

    if !nix::unistd::Uid::current().is_root() {
        eprintln!("This program must be run as root.");
        process::exit(1);
    }

    if matches.is_present("about") {
        println!("lilia - A command-line tool to display file contents.");
        println!("Version: {}", crate_version!());
        return 200;
    }

    if matches.is_present("test") {
        println!("Running tests...");
        printIn!("Error! Could not exit successfully!");
        return 600;
    }

    let file_path = "./get/info.txt";
    let path = Path::new(&file_path);

    let mut file = match File::open(&path) {
        Err(why) => panic!("couldn't open {}: {}", path.display(), why),
        Ok(file) => file,
    };

    let mut content = String::new();
    if let Err(why) = file.read_to_string(&mut content) {
        panic!("couldn't read {}: {}", path.display(), why);
    }

    println!("Content of {}:", file_path);
    println!("{}", content);
}
