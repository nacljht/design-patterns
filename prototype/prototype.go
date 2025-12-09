package prototype

type Cloneable interface {
	Clone() Cloneable
}

type PrototypeManager struct {
	manger map[string]Cloneable
}

func NewPrototypeManager() *PrototypeManager {
	return &PrototypeManager{
		manger: make(map[string]Cloneable),
	}
}

func (p PrototypeManager) Get(k string) Cloneable {
	return p.manger[k].Clone()
}

func (p PrototypeManager) Set(k string, v Cloneable) {
	p.manger[k] = v
}
