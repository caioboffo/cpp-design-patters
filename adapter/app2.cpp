class point_t
{
public:
    int x, y;
};

class manipulator_t
{
public:
    int a;
};

class shape_t
{
public:
    virtual void bounding_box(point_t &bottom_left,
                             point_t &bottom_right) const;
    virtual manipulator_t *create_manipulator() const;
};

class coord_t
{
public:
    int b;
};

class text_view_t
{
public:
    void get_origin(coord_t &x, coord_t &y) const;
    void get_extent(coord_t &width, coord_t &height) const;
    virtual bool is_empty() const;
};

class text_shape : public shape_t, private text_view_t
{
public:
    virtual void bounding_box(point_t &bottom_left,
                              point_t &bottom_right) const override;

    virtual bool is_empty() const override;
    virtual manipulator_t *create_manipulator() const override;
};
