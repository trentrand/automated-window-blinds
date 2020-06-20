const { Board, Led } = require('johnny-five');
const firmata = require('firmata');

const VirtualSerialPort = require('udp-serial').SerialPort;

const wirelessSerialPort = new VirtualSerialPort({
  host: '192.168.1.251', // TODO: use bonjour to mitigate dynamic IP maintenance?
  type: 'udp4',
  port: 1025,
});

const io = new firmata.Board(wirelessSerialPort)

io.once('ready', () => {
  console.log('Serial interface connected...');
  io.isReady = true;

  const board = new Board({ io, repl: true });
  const LED_PIN = 7;

  board.on("ready", () => {
    console.log('Main board ready...');
    board.isReady = true;

    const led = Led(LED_PIN);
    led.blink(500);
  });
});
