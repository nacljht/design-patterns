package observer

type Reader struct {
	name    string
	message string
}

type Observer interface {
	notify(*Subject)
	GetMessage() string
}

type Subject struct {
	message   string
	observers []Observer
}

func NewSubject() *Subject {
	return &Subject{
		observers: make([]Observer, 0),
	}
}

func NewReader(name string) *Reader {
	return &Reader{
		name: name,
	}
}

func (r *Reader) GetMessage() string {
	return r.message
}

func (r *Reader) notify(s *Subject) {
	r.message = s.message
}

func (s *Subject) Attach(r Observer) {
	s.observers = append(s.observers, r)
}

func (s *Subject) UpdateContext(message string) {
	s.message = message
	for _, o := range s.observers {
		o.notify(s)
	}
}
