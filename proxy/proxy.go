package proxy

// func TestProxy(t *testing.T) {
// 	var sub Subject
// 	sub = &Proxy{}

// 	res := sub.Do()

// 	if res != "pre:real:after" {
// 		t.Fail()
// 	}
// }

type Subject interface {
	Do() string
}

type realSubject struct{}

func (*realSubject) Do() string {
	return "real"
}

type Proxy struct {
	*realSubject
}

func (p *Proxy) Do() string {
	ret := "pre:"
	ret += p.realSubject.Do()
	ret += ":after"
	return ret
}
