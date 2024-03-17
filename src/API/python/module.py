def get(device_name):
    with open('info.txt', 'r') as file:
        for line in file:
            if f'{device_name}:"' in line:
                return line.split(':')[1].strip('"')
    return "Device not found"