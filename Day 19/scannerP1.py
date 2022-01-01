# Both parts take roughly 3-5 minutes to run
# Also manually transformed input a little bit becaus I don't know regex :(
discoveredBeacons = set()
discoveredScanners = []
closedScanners = []
class Scanner:
    totalScanners = 0
    def __init__(self, beacons, id):
        Scanner.totalScanners+=1
        self.id = id
        self.detectedBeacons = beacons
        self.position = None
        self.allOrientations = [self.rotate(i) for i in range(24)]
    def __eq__(self, __o):
        return self.id == __o.id
    # thanks to @LoicH: https://github.com/LoicH for this function which I very quickly copy pasta'd because i was too lazy to come up with them myself
    def rotate(self, i: int) -> None:
        def rotations(beacon, i) -> tuple:
            x, y, z = beacon
            rotates = [[x, y, z],
                    [z, y, -x],
                    [-x, y, -z],
                    [-z, y, x],
                    [-x, -y, z],
                    [-z, -y, -x],
                    [x, -y, -z],
                    [z, -y, x],
                    [x, -z, y],
                    [y, -z, -x],
                    [-x, -z, -y],
                    [-y, -z, x],
                    [x, z, -y],
                    [-y, z, -x],
                    [-x, z, y],
                    [y, z, x],
                    [z, x, y],
                    [y, x, -z],
                    [-z, x, -y],
                    [-y, x, z],
                    [-z, -x, y],
                    [y, -x, z],
                    [z, -x, -y],
                    [-y, -x, -z]]
            return rotates[i]
        newBeacons = [rotations(beacon, i) for beacon in self.detectedBeacons]
        return newBeacons
with open("D:\Programming\AoC2021\Day 19\scanner1.in", "r") as f:
    scanners = [Scanner([tuple(int(k) for k in j.split(',')) for j in i.split("\n") if j != ""], id) for (id, i) in enumerate(f.read().split("\n---\n"))]
    discoveredScanners.append(scanners[0])
    for beacon in scanners[0].detectedBeacons:
        discoveredBeacons.add(tuple(beacon))
    closedScanners.append(scanners[0])
    scanners.remove(scanners[0])
    scanners[0].position = (0,0,0) 
def findOverlap(scanner, otherScanner):
    for beacon in scanner.detectedBeacons:
        for rotatedOrientation in otherScanner.allOrientations:
            for rotatedBeacon in rotatedOrientation: 
                overlappingCount = 0
                otherScannerX, otherScannerY, otherScannerZ = (beacon[0]+(rotatedBeacon[0]*-1), beacon[1]+(rotatedBeacon[1]*-1), beacon[2]+(rotatedBeacon[2]*-1))
                for _rotatedBeacon in rotatedOrientation:
                    for _beacon in scanner.detectedBeacons:
                        if (_rotatedBeacon[0]+otherScannerX == _beacon[0] and _rotatedBeacon[1]+otherScannerY == _beacon[1] and _rotatedBeacon[2]+otherScannerZ == _beacon[2]):
                            overlappingCount+=1
                if overlappingCount >= 12:
                    discoveredScanners.append(otherScanner)
                    otherScanner.position = (otherScannerX, otherScannerY, otherScannerZ)
                    otherScanner.detectedBeacons = rotatedOrientation
                    for beacon in otherScanner.detectedBeacons:
                        beacon[0] += otherScannerX
                        beacon[1] += otherScannerY
                        beacon[2] += otherScannerZ
                        discoveredBeacons.add(tuple(beacon))
                    closedScanners.append(otherScanner)
                    scanners.remove(otherScanner)
                    return True
    return False
while (len(discoveredScanners) != Scanner.totalScanners):
    scanner = closedScanners.pop()
    for otherScanner in scanners.copy():
        if (otherScanner != scanner and otherScanner not in discoveredScanners):
            print(scanner.id, otherScanner.id)
            findOverlap(scanner, otherScanner)
print("Total beacons:", len(discoveredBeacons))
for scanner in discoveredScanners:
    print("Scanner {} location: {}".format(scanner.id, scanner.position))

