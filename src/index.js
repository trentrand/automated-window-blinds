const { Board, Led,Pin  } = require('johnny-five');
const { EtherPortClient } = require('etherport-client');

var board = new Board({
  port: new EtherPortClient({
    host: '192.168.1.90', // TODO: use bonjour to mitigate dynamic IP maintenance?
    port: 3030
  }),
  timeout: 1e5,
  repl: false,
});

board.on("ready", function() {
  console.log("READY!");
  board.isReady = true;


  const LED_PIN = 16;
  board.pinMode(LED_PIN, Pin.OUTPUT);
  const led = Led(LED_PIN);
  led.blink(500);
});
