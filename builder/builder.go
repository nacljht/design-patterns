package builder

type Builder interface {
	Buildpart1()
	Buildpart2()
	Buildpart3()
}

type Director struct {
	b Builder
}

func NewDirector(b Builder) *Director {
	return &Director{
		b: b,
	}
}

func (d *Director) Construct() {
	d.b.Buildpart1()
	d.b.Buildpart2()
	d.b.Buildpart3()
}

type Builder1 struct {
	result string
}

func (b *Builder1) Buildpart1() {
	b.result += "1"
}

func (b *Builder1) Buildpart2() {
	b.result += "2"
}

func (b *Builder1) Buildpart3() {
	b.result += "3"
}

func (b *Builder1) GetResult() string {
	return b.result
}

type Builder2 struct {
	result int
}

func (b *Builder2) Buildpart1() {
	b.result += 1
}

func (b *Builder2) Buildpart2() {
	b.result += 2
}

func (b *Builder2) Buildpart3() {
	b.result += 3
}

func (b *Builder2) GetResult() int {
	return b.result
}
