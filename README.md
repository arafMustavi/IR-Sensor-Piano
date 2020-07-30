# Gesture-Piano

A piano is built using a Piezo-electric Buzzer to produce the basic 8 notes of PIANO


Summary
We had an array of IR proximity sensors, each corresponding to one of the notes of a piano. 
These sensors was our input.
The output signals will be received by a piezo-electric buzzer, and particular notes will be played


Working Principle
We used the microcontroller, along with an external circuit consisting of resistors and capacitors to produce signals of different frequencies. 
These signals was then be fed into the buzzer, which produced the corresponding sound. (Do Re Mi Fa Sol La Si Do)
We used Pulse Width Modulation of signals to achieve our goal.
We were a little bit ambitious, and instead of designing the piano with push buttons, we used finger gestures to play it. 
In place of the buttons, we used IR sensors . 
When a finger comes close enough to a particular IR sensor, a particular note will be played.
