package state

import "testing"

func TestWeek(t *testing.T) {
	ctx := NewDayContext()

	results := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
	for i := 0; i < 8; i++ {
		if ctx.Today() != results[i%7] {
			t.Fail()
		}
		ctx.Next()
	}
}
