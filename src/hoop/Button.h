#ifndef BUTTON_H
#define BUTTON_H

#define DEBOUNCE_DELAY 50

// A pull-up button
class Button {
	public:
		Button(int pin) : _pin(pin) {}
   
    bool wasClicked() {
      bool wasClicked = false;
      _currentState = digitalRead(_pin);
    
      if (_currentState != _previousState) {
        if (_currentState == LOW) {
          wasClicked = true;
        }
    
        _previousState = _currentState;
        
        delay(DEBOUNCE_DELAY);
      }

      return wasClicked;
    }
  
	private:
    int _pin;
		int _previousState = 0;
		int _currentState = 0;
};

#endif /* BUTTON_H */
