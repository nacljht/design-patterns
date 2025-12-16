package state

type Context interface {
	Next()
}

type State interface {
	Handle(ctx Context)
}

type DayContext struct {
	state DayState
}

type DayState struct {
	day string
}

func (d DayState) Get() string {
	return d.day
}

func newDayState(day string) DayState {
	return DayState{
		day: day,
	}
}

func (d *DayContext) Next() {
	d.state.Handle(d)
}

func (d *DayContext) Today() string {
	return d.state.Get()
}

func (d DayState) Handle(ctx *DayContext) {
	days := []string{"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"}
	for i, day := range days {
		if day == d.Get() {
			ctx.state = newDayState(days[(i+1)%7])
		}
	}
}

func NewDayContext() *DayContext {
	return &DayContext{
		state: newDayState("Sunday"),
	}
}
