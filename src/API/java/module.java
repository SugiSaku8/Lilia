import java.io.IOException;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.util.stream.Stream;

public class Lilia {
    public static String get(String deviceName) {
        try (Stream<String> lines = Files.lines(Paths.get("info.txt"))) {
            return lines
                    .filter(line -> line.startsWith(deviceName + ":"))
                    .findFirst()
                    .map(line -> line.split(":")[1].replaceAll("^\"|\"$", ""))
                    .orElse("Device not found");
        } catch (IOException e) {
            e.printStackTrace();
            return "Error reading file";
        }
    }

    public static void main(String[] args) {
        System.out.println(get("cpu"));
    }
}
