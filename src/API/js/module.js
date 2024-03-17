const fs = require('fs');

function get(deviceName) {
    const data = fs.readFileSync('info.txt', 'utf8');
    const lines = data.split('\n');
    for (let line of lines) {
        if (line.startsWith(`${deviceName}:"`)) {
            return line.split(':')[1].slice(1, -1);
        }
    }
    return "Device not found";
}