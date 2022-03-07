# PATRÓN OBSERVER

## FUNCIONALIDAD

> Permite crear un mecanismo en donde hay un publicador y un seguidor que está suscrito al publicador, colocándose a la espera de una nueva publicación, así como se da en la mayoría de las notificaciones o cuando te suscribes a una revista y esperas nuevo contenido. Esto es lo que nos permite hacer Observer.

## IMPLEMENTACIÓN
 > Para la implementación, debemos tener el claro los conceptos de polimorfismo porque la idea es que el usuario pueda ser suscriptor y dejar de serlo en cualquier momento, para ello, usamos algo llamado interfaces. Aunque, C no soporta la programación orientada a objetos, también se puedes hacer ciertas cosas parecidas y de esta forma "recitar el mismo comportamiento".
 > Para ello, primero es la creación del Subject, en un archivo .h se definen los métodos y atributos, en este caso, el subject debe permitir añadir observadores, eliminarlos, almacenarlos y notificarles sobre el nuevo evento. Posteriormente, nos ocuparemos del Observador, este debe contar con un método por el cual va a ser notificado por el subject.

Ahora bien, en una implementación real, con las bases anteriores, se deben crear las condiciones necesarias para que se haga la relación y se pueda deshacer fácilmente.

### Ejemplo

En nuestro caso, tenemos una situación hipotética, es el juego de la ruleta en un casino, este pese a tener muchas reglas y muchos tipos de apuestas, aquí solo habrá una, Pleno; de modo, que los jugadores solo podrán apostar por un solo número. Cabe aclarar que, solo hay número del 1 al 9. de esta forma el ejemplo no queda tan extenso.

Bueno, se sabe que solo hay un subject, en nuestro caso, el Crupier (quien lanza la pequeña pelota en la ruleta) y hay varios observadores, en nuestro caso, serán llamados Apostadores, entonces el punto es que ellos se encuentran observando al Crupier a la espera de saber en donde se detiene la pelota, e intentan predecir donde apostando. Por lo que, para ellos poder jugar, deben suscribirse al crupier y si quieres dejar de jugar, con el método unregistered, lo puedes hacer.

El crupier debe tener en sus archivos la definición del evento, donde lanza aleatoriamente la pelota, luego del _aciertoEvent_, les avisa a todos sus suscriptores y les cuenta en cuál evento quedó. Mientras, el observador debe tener un método que recoja al evento y procesa a actuar, en este caso, es verificar que si acertó o no con la apuesta.



Ahora bien, para agregar más subjects, en el caso del ejemplo es darle un contexto, por ello, de una situación hipotética, haya un ayudante al crupier, que, si ningún participante acertó, él lancé la pelota, pero en la casilla del cero (dentro de las reglas del juego esto tiene varias implicaciones, pero como no vienen al caso, se pasarán por alto), los participantes, se suscriben a este nuevo asistente y esperan a que si no gana nadie, sean notificados, entonces ellos no estarían pendientes de quién no ganó, sino a la espera del anuncio del asistente y la remuneración la casilla cero.

así que realmente es coger la misma base del Subject y crear un nuevo .c y .h llamado _AsistenteCrupier_, su evento se aplicaría de forma distinta y su lista de seguidores también, aquí caemos en cuenta que un seguir puede estar suscrito a varios publicadores.


