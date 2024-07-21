//Get the path to the script_version.hpp file
let version = HEMTT_VFS
        .join("addons")
        .join("main")
        .join("script_version.hpp");
// Create (or overwrite) the file
let out = version.create_file();
let build = date("[year repr:last_two][month][day]");
out.write("#define MAJOR " + HEMTT.project().version().major() + "\n");
out.write("#define MINOR " + HEMTT.project().version().minor() + "\n");
out.write("#define PATCH " + HEMTT.project().version().patch() + "\n");
out.write("#define BUILD " + build + "\n");
print("Set version to " + HEMTT.project().version().to_string());
